#ifndef PLAYERSTRUCT_H
#define PLAYERSTRUCT_H

#include <Server/Structs/BlockStruct.h>
#include <Server/Structs/CommandStruct.h>
#include <Server/Structs/GrenadeStruct.h>
#include <Server/Structs/IPStruct.h>
#include <Server/Structs/MapStruct.h>
#include <Server/Structs/MovementStruct.h>
#include <Server/Structs/TimerStruct.h>
#include <Util/Enums.h>
#include <Util/Queue.h>
#include <Util/Types.h>
#include <Util/Uthash.h>
#include <enet/enet.h>
#include <stdint.h>

#define PLAYER_NAME_STRLEN 16

typedef struct player
{
    UT_hash_handle           hh;
    queue_t*                 map_queue;
    ENetPeer*                peer;
    grenade_t*               grenade;
    uint64_t                 permissions;
    string_node_t*           current_periodic_message;
    block_node_t*            blockBuffer;
    timers_t                 timers;
    permissions_t            role_list[5]; // Change me based on the number of access levels you require
    state_t                  state;
    weapon_t                 weapon;
    team_t                   team;
    tool_t                   item;
    weapon_default_clip_t    default_clip;
    weapon_default_reserve_t default_reserve;
    uint32_t                 kills;
    uint32_t                 deaths;
    int                      version_minor;
    int                      version_major;
    int                      version_revision;
    color_t                  tool_color;
    int                      hp;
    float                    lastclimb;
    ip_t                     ip;
    vector3f_t               locAtClick;
    movement_t               movement;
    vector3i_t               result_line[50];
    uint16_t                 ups;
    char                     client;
    uint8_t                  id;
    uint8_t                  respawn_time;
    uint8_t                  grenades;
    uint8_t                  blocks;
    uint8_t                  weapon_reserve;
    uint8_t                  weapon_clip;
    uint8_t                  weapon_pellets;
    uint8_t                  alive;
    uint8_t                  input;
    uint8_t                  allow_killing;
    uint8_t                  allow_team_killing;
    uint8_t                  muted;
    uint8_t                  admin_muted;
    uint8_t                  can_build;
    uint8_t                  told_to_master;
    uint8_t                  has_intel;
    uint8_t                  is_invisible;
    uint8_t                  welcome_sent;
    uint8_t                  reloading;
    uint8_t                  spam_counter;
    uint8_t                  periodic_delay_index;
    uint8_t                  invalid_pos_count;
    uint8_t                  move_forward;
    uint8_t                  move_backwards;
    uint8_t                  move_left;
    uint8_t                  move_right;
    uint8_t                  jumping;
    uint8_t                  crouching;
    uint8_t                  sneaking;
    uint8_t                  sprinting;
    uint8_t                  primary_fire;
    uint8_t                  secondary_fire;
    uint8_t                  airborne;
    uint8_t                  wade;
    uint8_t                  next_shot_invalid;
    char                     name[PLAYER_NAME_STRLEN + 1];
    char                     os_info[255];
} player_t;

#endif
