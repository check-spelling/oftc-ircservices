#ifndef CHANSERV_H
#define CHANSERV_H

struct RegChannel
{
  dlink_node node;
  
  unsigned int id;
  char channel[CHANNELLEN+1];
  char *description;
  char *entrymsg; 
  char *url;
  char *email;
  char *topic;
  char forbidden;
  char priv;
  char restricted_ops;
  char topic_lock;
  char verbose;
};

#define CS_HELP_REG_SHORT 1
#define CS_HELP_REG_LONG 2
#define CS_HELP_SHORT 3
#define CS_HELP_LONG 4
#define CS_HELP_SET_DESC_SHORT 5
#define CS_HELP_SET_DESC_LONG 6
#define CS_HELP_SET_URL_SHORT 7
#define CS_HELP_SET_URL_LONG 8
#define CS_HELP_SET_EMAIL_SHORT 9
#define CS_HELP_SET_EMAIL_LONG 10
#define CS_HELP_SET_ENTRYMSG_SHORT 11
#define CS_HELP_SET_ENTRYMSG_LONG 12
#define CS_HELP_SET_TOPIC_SHORT 13
#define CS_HELP_SET_TOPIC_LONG 14
#define CS_HELP_SET_TOPICLOCK_SHORT 15
#define CS_HELP_SET_TOPICLOCK_LONG 16
#define CS_HELP_SET_PRIVATE_SHORT 17
#define CS_HELP_SET_PRIVATE_LONG 18
#define CS_HELP_SET_RESTRICTED_SHORT 19
#define CS_HELP_SET_RESTRICTED_LONG 20
#define CS_HELP_SET_VERBOSE_SHORT 21
#define CS_HELP_SET_VERBOSE_LONG 22
#define CS_HELP_SET_MLOCK_SHORT 23
#define CS_HELP_SET_MLOCK_LONG 24
#define CS_HELP_SET_AUTOLIMIT_SHORT 25
#define CS_HELP_SET_AUTOLIMIT_LONG 26
#define CS_HELP_SET_EXPIREBANS_SHORT 27
#define CS_HELP_SET_EXPIREBANS_LONG 28
#define CS_HELP_SET_SHORT 29
#define CS_HELP_SET_LONG 30
#define CS_HELP_AKICK_ADD_SHORT 31
#define CS_HELP_AKICK_ADD_LONG 32
#define CS_HELP_AKICK_DEL_SHORT 33
#define CS_HELP_AKICK_DEL_LONG 34
#define CS_HELP_AKICK_LIST_SHORT 35
#define CS_HELP_AKICK_LIST_LONG 36
#define CS_HELP_AKICK_ENFORCE_SHORT 37
#define CS_HELP_AKICK_ENFORCE_LONG 38
#define CS_HELP_AKICK_SHORT 39
#define CS_HELP_AKICK_LONG 40
#define CS_HELP_DROP_SHORT 41
#define CS_HELP_DROP_LONG 42
#define CS_HELP_DEOP_SHORT 43
#define CS_HELP_DEOP_LONG 44
#define CS_HELP_INFO_SHORT 45
#define CS_HELP_INFO_LONG 46
#define CS_HELP_OP_SHORT 47
#define CS_HELP_OP_LONG 48
#define CS_HELP_UNBAN_SHORT 49
#define CS_HELP_UNBAN_LONG 50
#define CS_HELP_INVITE_SHORT 51
#define CS_HELP_INVITE_LONG 52
#define CS_HELP_CLEAR_SHORT 53
#define CS_HELP_CLEAR_LONG 54
#define CS_HELP_ACCESS_SHORT 55
#define CS_HELP_ACCESS_LONG 56
#define CS_HELP_CLEAR_BANS_SHORT 57
#define CS_HELP_CLEAR_BANS_LONG 58
#define CS_HELP_CLEAR_OPS_SHORT 59
#define CS_HELP_CLEAR_OPS_LONG 60
#define CS_HELP_CLEAR_VOICES_SHORT 61
#define CS_HELP_CLEAR_VOICES_LONG 62
#define CS_HELP_CLEAR_USERS_SHORT 63
#define CS_HELP_CLEAR_USERS_LONG 64
#define CS_HELP_ACCESS_ADD_SHORT 65
#define CS_HELP_ACCESS_ADD_LONG 66
#define CS_HELP_ACCESS_DEL_SHORT 67
#define CS_HELP_ACCESS_DEL_LONG 68
#define CS_HELP_ACCESS_LIST_SHORT 69
#define CS_HELP_ACCESS_LIST_LONG 70
#define CS_REGISTER_NICK 71
#define CS_ALREADY_REG 72
#define CS_REG_SUCCESS 73
#define CS_REG_FAIL 74
#define CS_NAMESTART_HASH 75
#define CS_NOT_ONCHAN 76
#define CS_NOT_OPPED 77
#define CS_NOT_REG 78
#define CS_DROPPED 79
#define CS_DROP_FAILED 80
#define CS_SET_SUCCESSOR 81
#define CS_SET_DESCRIPTION 82
#define CS_SET_ENTRYMSG 83
#define CS_SET_SUCC 84
#define CS_SET_SUCC_FAILED 85
#define CS_SET_DESC 86
#define CS_SET_DESC_FAILED 87
#define CS_SET_URL 88
#define CS_SET_URL_FAILED 89
#define CS_SET_EMAIL 90
#define CS_SET_EMAIL_FAILED 91
#define CS_SET_MSG 92
#define CS_SET_MSG_FAILED 93
#define CS_SET_TOPIC 94
#define CS_SET_TOPIC_FAILED 95
#define CS_SET_FLAG 96
#define CS_SET_SUCCESS 97
#define CS_SET_FAILED 98
#define CS_NOT_EXIST 99
#define CS_INFO_CHAN 100
#define CS_AKICK_NONICK 101
#define CS_AKICK_ADDED 102
#define CS_AKICK_ADDFAIL 103
#define CS_AKICK_LIST 104
#define CS_AKICK_LISTEND 105
#define CS_AKICK_DEL 106
#define CS_AKICK_ENFORCE 107
#define CS_CHAN_NOT_USED 108
#define CS_CLEAR_BANS 109
#define CS_CLEAR_OPS 110
#define CS_CLEAR_VOICES 111
#define CS_CLEAR_USERS 112
#define CS_NOT_ON_CHAN 113
#define CS_OP 114
#define CS_DEOP 115
#define CS_NICK_NOT_ONLINE 116
#define CS_ALREADY_ON_CHAN 117
#define CS_INVITED 118
#define CS_ACCESS_BADLEVEL 119
#define CS_ACCESS_ADDOK 120
#define CS_ACCESS_ADDFAIL 121
#define CS_ACCESS_LIST 122
#define CS_ACCESS_LISTEND 123
#define CS_ACCESS_DELOK 124
#define CS_ACCESS_DELFAIL 125
#define CS_ENTRYMSG 126

#endif
