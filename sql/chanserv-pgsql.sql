DROP TABLE IF EXISTS channel CASCADE;
CREATE TABLE channel(
  id                    SERIAL PRIMARY KEY,
  channel               VARCHAR(255) NOT NULL,
  flag_private          BOOLEAN NOT NULL DEFAULT 'False', -- do not show up in list of channels
  flag_restricted       BOOLEAN NOT NULL DEFAULT 'False', -- only people on the access list can hold channel operator status
  flag_topic_lock       BOOLEAN NOT NULL DEFAULT 'False', -- topics can only be changed via chanserv
  flag_verbose          BOOLEAN NOT NULL DEFAULT 'False', -- notice all chanserv actions to the channel
  flag_autolimit        BOOLEAN NOT NULL DEFAULT 'False', -- sets limit just above the current user count
  flag_expirebans       BOOLEAN NOT NULL DEFAULT 'False', -- Expire old bans
  flag_floodserv        BOOLEAN NOT NULL DEFAULT 'False', -- floodserv should monitor channel
  flag_autoop           BOOLEAN NOT NULL DEFAULT 'False', -- CHANOP or above get op on join
  flag_autovoice        BOOLEAN NOT NULL DEFAULT 'False', -- MEMBER or above get voice on join
  flag_leaveops         BOOLEAN NOT NULL DEFAULT 'False', -- Don't deop people who get chanop but shouldnt
  flag_autosave         BOOLEAN NOT NULL DEFAULT 'False', -- Manually issued CMODEs are persisted in the DB
  description           VARCHAR(512) NOT NULL,
  url                   VARCHAR(255),
  email                 VARCHAR(255),
  entrymsg              VARCHAR(512),
  topic                 VARCHAR(512),
  mlock                 VARCHAR(255),
  expirebans_lifetime   INTEGER NOT NULL DEFAULT 300,
  reg_time              INTEGER NOT NULL,
  last_used             INTEGER NOT NULL
);
CREATE UNIQUE INDEX channel_channel_idx ON channel (irc_lower(channel));

DROP TABLE IF EXISTS channel_access;
CREATE TABLE channel_access(
  id                   SERIAL PRIMARY KEY,
  channel_id           INTEGER NOT NULL REFERENCES channel(id) ON DELETE CASCADE,
  account_id           INTEGER REFERENCES account(id),
  group_id             INTEGER REFERENCES "group"(id),
  level                INTEGER NOT NULL,
  UNIQUE (channel_id, account_id)
);
CREATE INDEX channel_access_account_id_idx ON channel_access (account_id);

DROP TABLE IF EXISTS channel_akick;
CREATE TABLE channel_akick(
  id                  SERIAL PRIMARY KEY,
  channel_id          INTEGER NOT NULL REFERENCES channel(id) ON DELETE CASCADE,
  setter              INTEGER REFERENCES account(id) ON DELETE SET NULL,
  target              INTEGER REFERENCES account(id) ON DELETE CASCADE, -- If a nickname akick
  mask                VARCHAR(255), -- If a mask akick
  reason              VARCHAR(512) NOT NULL,
  time                INTEGER NOT NULL,
  duration            INTEGER NOT NULL,
  chmode              INTEGER NOT NULL DEFAULT 0
	CHECK (((target IS NULL) OR (mask IS NULL)) AND NOT ((target IS NULL) AND 
	(mask IS NULL)))
);

DROP TABLE IF EXISTS forbidden_channel;
CREATE TABLE forbidden_channel (
  channel             VARCHAR(255) PRIMARY KEY
);
-- this is not so much for performance as for unique constraint reasons:
CREATE UNIQUE INDEX forbidden_channel_channel_idx ON forbidden_channel (irc_lower(channel));
CREATE UNIQUE INDEX channel_akick_mode_mask_idx ON channel_akick(channel_id, chmode, mask);
CREATE UNIQUE INDEX channel_akick_mode_target_idx ON channel_akick(channel_id, chmode, target);
