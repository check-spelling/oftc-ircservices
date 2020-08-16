DROP TABLE IF EXISTS "group" CASCADE;
CREATE TABLE "group" (
  id                  SERIAL PRIMARY KEY,
  name                VARCHAR(32) NOT NULL,
  description         VARCHAR(255),
  url                 VARCHAR(255),
  email               VARCHAR(255),
  flag_private        BOOLEAN NOT NULL DEFAULT 'False',
  reg_time            INTEGER NOT NULL 
);

CREATE UNIQUE INDEX group_lower_name_idx ON "group" (irc_lower(name));

DROP TABLE IF EXISTS group_access;
CREATE TABLE group_access(
  id                   SERIAL PRIMARY KEY,
  group_id             INTEGER NOT NULL REFERENCES "group"(id) ON DELETE CASCADE,
  account_id           INTEGER NOT NULL REFERENCES account(id),
  level                INTEGER NOT NULL,
  UNIQUE (group_id, account_id)
);
CREATE INDEX group_access_account_id_idx ON group_access (account_id);
