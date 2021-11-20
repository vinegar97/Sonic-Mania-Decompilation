#ifndef OBJ_RUBYPORTAL_H
#define OBJ_RUBYPORTAL_H

#include "SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    Hitbox hitbox;
    uint16 aniFrames;
#if RETRO_USE_PLUS
    bool32 openPortal;
#endif
} ObjectRubyPortal;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    int32 timer;
    Animator animator;
    Hitbox hitbox;
} EntityRubyPortal;

// Object Struct
extern ObjectRubyPortal *RubyPortal;

// Standard Entity Events
void RubyPortal_Update(void);
void RubyPortal_LateUpdate(void);
void RubyPortal_StaticUpdate(void);
void RubyPortal_Draw(void);
void RubyPortal_Create(void* data);
void RubyPortal_StageLoad(void);
#if RETRO_INCLUDE_EDITOR
void RubyPortal_EditorDraw(void);
void RubyPortal_EditorLoad(void);
#endif
void RubyPortal_Serialize(void);

// Extra Entity Functions
#if RETRO_USE_PLUS
void RubyPortal_HandleTileDestruction(void);
#endif
void RubyPortal_State_AwaitOpenTMZ2(void);
void RubyPortal_State_Opening(void);
void RubyPortal_State_Opened(void);
#if RETRO_USE_PLUS
void RubyPortal_State_SaveGameState(void);
#endif
void RubyPortal_State_Open_WarpDoor(void);
void RubyPortal_State_Open_Cutscene(void);
#if RETRO_USE_PLUS
void RubyPortal_State_EncoreEnd(void);
void RubyPortal_State_EncoreRampage(void);
#endif

#endif //!OBJ_RUBYPORTAL_H
