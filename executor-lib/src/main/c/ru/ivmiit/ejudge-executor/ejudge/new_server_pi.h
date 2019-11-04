/* -*- c -*- */
#ifndef __NEW_SERVER_PI_H__
#define __NEW_SERVER_PI_H__

/* Copyright (C) 2014-2017 Alexander Chernov <cher@ejudge.ru> */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "../ejudge/ej_types.h"

#include "../ejudge/external_action.h"

#include <time.h>

typedef struct PrivUserInfo
{
  int user_id;
  unsigned char *login;
  unsigned char *name;
  unsigned int role_mask;
} PrivUserInfo;

typedef struct PrivUserInfoArray
{
    int a, u;
    struct PrivUserInfo **v;
} PrivUserInfoArray;

typedef struct PrivViewPrivUsersPage
{
    PageInterface b;
    PrivUserInfoArray users;
} PrivViewPrivUsersPage;

/* */

typedef struct PrivUserIPItem
{
  int user_id;
  int ip_u;
  int ip_a;
  ej_ip_t *ips;
} PrivUserIPItem;

typedef struct PrivUserIPArray
{
    int a, u;
    PrivUserIPItem **v;
} PrivUserIPArray;

typedef struct PrivViewUserIPsPage
{
    PageInterface b;
    PrivUserIPArray users;
} PrivViewUserIPsPage;

/* */

typedef struct PrivIPUserItem
{
    ej_ip_t ip;
    unsigned char *ip_str;
    int uid_u, uid_a;
    int *uids;
} PrivIPUserItem;

typedef struct PrivIPUserArray
{
    int a, u;
    PrivIPUserItem *v;
} PrivIPUserArray;

typedef struct PrivViewIPUsersPage
{
    PageInterface b;
    PrivIPUserArray ips;
} PrivViewIPUsersPage;

/* === Testing queue === */

struct super_run_in_packet;
typedef struct TestingQueueEntry
{
  unsigned char *queue_id;
  unsigned char *entry_name;
  int priority;
  time_t mtime;
  struct super_run_in_packet *packet;
} TestingQueueEntry;

typedef struct TestingQueueArray
{
  int a;
  int u;
  struct TestingQueueEntry *v;
} TestingQueueArray;

#define ej_fix_prio(x) (((x) < -16)?-16:(((x) > 15)?15:(x)))

TestingQueueArray *testing_queue_array_free(TestingQueueArray *parr, int free_struct_flag);

/* === For unprivileged main page === */

typedef struct UserProblemInfo
{
    time_t deadline;
    time_t effective_time; // time to count time-based penalties
    int best_run;
    int attempts;
    int disqualified;
    int ce_attempts;
    int best_score;
    int prev_successes; // previous successes of other users on this problem
    int all_attempts;
    int eff_attempts; // all attempts except IGNORED and COMPILE_ERR
    int token_count;  // tokens spent on the problem
    unsigned char solved_flag;
    unsigned char accepted_flag;
    unsigned char pending_flag;
    unsigned char pr_flag;
    unsigned char trans_flag;
    unsigned char status;
    unsigned char last_untokenized;
    unsigned char marked_flag;
    unsigned char autook_flag;    // if "OK" is result of "provide_ok" setting
    unsigned char rejected_flag;  // if there are "Rejected" runs
    unsigned char need_eff_time_flag; // if effective time needs to be recorded
} UserProblemInfo;

/* */

typedef struct UserInfoPage
{
    unsigned char *user_login;
    unsigned char *user_name;
    unsigned char *status_str;

    unsigned char *create_time_str;
    unsigned char *last_login_time_str;

    unsigned char *avatar_store;
    unsigned char *avatar_id;
    unsigned char *avatar_suffix;

    size_t run_size;

    int user_id;
    int status;
    int run_count;
    int clar_count;
    int result_score;

    ejbytebool_t is_banned;
    ejbytebool_t is_invisible;
    ejbytebool_t is_locked;
    ejbytebool_t is_incomplete;
    ejbytebool_t is_disqualified;
    ejbytebool_t is_privileged;
    ejbytebool_t is_reg_readonly;
} UserInfoPage;

typedef struct UserInfoPageArray
{
    int a, u;
    struct UserInfoPage **v;
} UserInfoPageArray;

typedef struct PrivViewUsersPage
{
    PageInterface b;
    int result;
    char *message;
    UserInfoPageArray *users;
} PrivViewUsersPage;

typedef struct PublicLogExtraInfo
{
    const unsigned char *header_str;
    const unsigned char *footer_str;
    int user_mode;
} PublicLogExtraInfo;

typedef struct StandingsExtraInfo
{
    const unsigned char *stand_dir;
    const unsigned char *file_name;
    const unsigned char *file_name2;
    int users_on_page;
    int page_index;
    int client_flag;
    int only_table_flag;
    int user_id;
    const unsigned char *header_str;
    unsigned char const *footer_str;
    int accepting_mode;
    const unsigned char *user_name;
    int force_fancy_style;
    int charset_id;
    struct user_filter_info *user_filter;
    int user_mode;
    time_t stand_time;
} StandingsExtraInfo;

typedef struct LanguageStat
{
    int total_runs;
    int transient_runs;
    int success_runs;
    int check_failed_runs;
    int compilation_failed_runs;
    int pending_runs;
    int ignored_runs;
    int disqualified_runs;
    int partial_runs;
    int best_score;
} LanguageStat;

#endif /* __NEW_SERVER_PI_H__ */

/*
 * Local variables:
 *  c-basic-offset: 4
 * End:
 */
