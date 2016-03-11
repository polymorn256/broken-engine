/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 4 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"

#include "StdH.h"

#include <EntitiesMP/BloodSpray.h>
#include <EntitiesMP/BloodSpray_tables.h>
CEntityEvent *ESpawnSpray::MakeCopy(void) { CEntityEvent *peeCopy = new ESpawnSpray(*this); return peeCopy;}
ESpawnSpray::ESpawnSpray() : CEntityEvent(EVENTCODE_ESpawnSpray) {;
 ClearToDefault(sptType);
 ClearToDefault(fDamagePower);
 ClearToDefault(fSizeMultiplier);
 ClearToDefault(vDirection);
 ClearToDefault(penOwner);
 ClearToDefault(colCentralColor);
 ClearToDefault(fLaunchPower);
 ClearToDefault(colBurnColor);
};
void CBloodSpray::SetDefaultProperties(void) {
  m_sptType = SPT_NONE ;
  m_tmStarted = 0.0f;
  m_vDirection = FLOAT3D(0 , 0 , 0);
  m_penOwner = NULL;
  m_fDamagePower = 1.0f;
  m_boxSizedOwner = FLOATaabbox3D(FLOAT3D (0 , 0 , 0) , 0.01f);
  m_vGDir = FLOAT3D(0 , 0 , 0);
  m_fGA = 0.0f;
  m_fLaunchPower = 1.0f;
  m_colCentralColor = COLOR(C_WHITE  | CT_OPAQUE );
  m_boxOriginalOwner = FLOATaabbox3D(FLOAT3D (0 , 0 , 0) , 0.01f);
  m_colBurnColor = COLOR(C_WHITE  | CT_OPAQUE );
  m_penPrediction = NULL;
  CRationalEntity::SetDefaultProperties();
}
  
#line 48 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
void CBloodSpray::RenderParticles(void) 
#line 49 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
{
#line 50 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
switch(m_sptType )
#line 51 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
{
#line 52 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_BLOOD : 
#line 53 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_BONES : 
#line 54 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_FEATHER : 
#line 55 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_STONES : 
#line 56 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_WOOD : 
#line 57 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_SLIME : 
#line 58 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_LAVA_STONES : 
#line 59 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_SMALL_LAVA_STONES : 
#line 60 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_BEAST_PROJECTILE_SPRAY : 
#line 61 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_AIRSPOUTS : 
#line 62 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_GOO : 
#line 63 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
{
#line 64 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_BloodSpray  (m_sptType  , GetLerpedPlacement  () . pl_PositionVector  , m_vGDir  , m_fGA  , 
#line 65 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_boxSizedOwner  , m_vDirection  , m_tmStarted  , m_fDamagePower  , m_colBurnColor );
#line 66 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
break ;
#line 67 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
#line 68 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_COLOREDSTONE : 
#line 69 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
{
#line 70 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_BloodSpray  (m_sptType  , GetLerpedPlacement  () . pl_PositionVector  , m_vGDir  , m_fGA  , 
#line 71 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_boxSizedOwner  , m_vDirection  , m_tmStarted  , m_fDamagePower  , MulColors  (m_colCentralColor  , m_colBurnColor ));
#line 72 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
break ;
#line 73 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
#line 74 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_TREE01 : 
#line 75 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_BloodSpray  (SPT_WOOD  , GetLerpedPlacement  () . pl_PositionVector  , m_vGDir  , m_fGA  / 1.5f , 
#line 76 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_boxSizedOwner  , m_vDirection  , m_tmStarted  , m_fDamagePower  / 2.0f , m_colBurnColor );
#line 77 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_Leaves  (m_penOwner  , m_boxOriginalOwner  , GetLerpedPlacement  () . pl_PositionVector  , 
#line 78 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_fDamagePower  , m_fDamagePower  * m_fLaunchPower  , m_vGDir  , 
#line 79 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_fGA  / 2.0f , m_tmStarted  , MulColors  (m_colCentralColor  , m_colBurnColor ));
#line 80 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
break ;
#line 81 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_PLASMA : 
#line 82 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_BloodSpray  (m_sptType  , GetLerpedPlacement  () . pl_PositionVector  , m_vGDir  , m_fGA  , 
#line 83 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_boxSizedOwner  , m_vDirection  , m_tmStarted  , m_fDamagePower );
#line 84 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_DamageSmoke  (this  , m_tmStarted  , m_boxSizedOwner  , m_fDamagePower );
#line 85 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_ElectricitySparks  (this  , m_tmStarted  , 5.0f , 0.0f , 32);
#line 86 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
break ;
#line 87 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_ELECTRICITY_SPARKS : 
#line 88 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
{
#line 89 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_MetalParts  (this  , m_tmStarted  , m_boxSizedOwner  , m_fDamagePower );
#line 90 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_DamageSmoke  (this  , m_tmStarted  , m_boxSizedOwner  , m_fDamagePower );
#line 91 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_BloodSpray  (SPT_BLOOD  , GetLerpedPlacement  () . pl_PositionVector  , m_vGDir  , m_fGA  , 
#line 92 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_boxSizedOwner  , m_vDirection  , m_tmStarted  , m_fDamagePower  / 2.0f , C_WHITE  | CT_OPAQUE );
#line 93 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_ElectricitySparks  (this  , m_tmStarted  , 5.0f , 0.0f , 32);
#line 94 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
break ;
#line 95 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
#line 96 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
case SPT_ELECTRICITY_SPARKS_NO_BLOOD : 
#line 97 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
{
#line 98 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_MetalParts  (this  , m_tmStarted  , m_boxSizedOwner  , m_fDamagePower );
#line 99 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_DamageSmoke  (this  , m_tmStarted  , m_boxSizedOwner  , m_fDamagePower );
#line 100 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Particles_ElectricitySparks  (this  , m_tmStarted  , 5.0f , 0.0f , 32);
#line 101 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
#line 102 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
#line 103 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
BOOL CBloodSpray::
#line 111 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBloodSpray_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_ESpawnSpray, "CBloodSpray::Main expects 'ESpawnSpray' as input!");  const ESpawnSpray &eSpawn = (const ESpawnSpray &)__eeInput;
#line 113 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
InitAsEditorModel  ();
#line 114 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 115 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 116 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
SetPredictable  (TRUE );
#line 119 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
SetModel  (MODEL_MARKER );
#line 120 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 123 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_sptType  = eSpawn  . sptType ;
#line 124 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_vDirection  = eSpawn  . vDirection ;
#line 125 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_penOwner  = eSpawn  . penOwner ;
#line 126 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_fDamagePower  = eSpawn  . fDamagePower ;
#line 127 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_fLaunchPower  = eSpawn  . fLaunchPower ;
#line 128 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_colBurnColor  = eSpawn  . colBurnColor ;
#line 129 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_tmStarted  = _pTimer  -> CurrentTick  ();
#line 130 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_colCentralColor  = eSpawn  . colCentralColor ;
#line 133 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
if(eSpawn  . penOwner  == NULL  || eSpawn  . penOwner  -> en_pmoModelObject  == NULL )
#line 134 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
{
#line 136 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Destroy  ();
#line 137 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Return(STATE_CURRENT,EVoid());
#line 137 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
return TRUE;
#line 138 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
#line 140 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
if(eSpawn  . penOwner  -> en_RenderType  == RT_SKAMODEL ){
#line 141 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
eSpawn  . penOwner  -> GetModelInstance  () -> GetCurrentColisionBox  (m_boxSizedOwner );
#line 142 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}else {
#line 143 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
eSpawn  . penOwner  -> en_pmoModelObject  -> GetCurrentFrameBBox  (m_boxSizedOwner );
#line 144 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_boxOriginalOwner  = m_boxSizedOwner ;
#line 145 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_boxSizedOwner  . StretchByVector  (eSpawn  . penOwner  -> en_pmoModelObject  -> mo_Stretch  * eSpawn  . fSizeMultiplier );
#line 146 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_boxOriginalOwner  . StretchByVector  (eSpawn  . penOwner  -> en_pmoModelObject  -> mo_Stretch );
#line 147 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
#line 149 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
if(m_penOwner  -> GetPhysicsFlags  () & EPF_MOVABLE ){
#line 150 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_vGDir  = ((CMovableEntity  *) & * m_penOwner ) -> en_vGravityDir ;
#line 151 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_fGA  = ((CMovableEntity  *) & * m_penOwner ) -> en_fGravityA ;
#line 152 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}else {
#line 153 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
FLOATmatrix3D & m  = m_penOwner  -> en_mRotation ;
#line 154 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_vGDir  = FLOAT3D (- m  (1 , 2) , - m  (2 , 2) , - m  (3 , 2));
#line 155 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
m_fGA  = 30.0f;
#line 156 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
#line 158 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
FLOAT fWaitTime  = 4.0f;
#line 159 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
if(m_sptType  == SPT_ELECTRICITY_SPARKS  || m_sptType  == SPT_ELECTRICITY_SPARKS_NO_BLOOD )
#line 160 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
{
#line 161 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
fWaitTime  = 4.0f;
#line 162 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
}
#line 163 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
SetTimerAfter(fWaitTime );
Jump(STATE_CURRENT, 0x025b0001, FALSE, EBegin());return TRUE;}BOOL CBloodSpray::H0x025b0001_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x025b0001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x025b0002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBloodSpray::H0x025b0002_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x025b0002
;
#line 164 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Destroy  ();
#line 166 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
Return(STATE_CURRENT,EVoid());
#line 166 "D:/SE1_GPL/Sources/EntitiesMP/BloodSpray.es"
return TRUE; ASSERT(FALSE); return TRUE;};