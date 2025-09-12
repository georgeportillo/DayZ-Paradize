class eAI_Vehicles_GoTo_State_0 extends eAIState {
eAI_Vehicles_FSM_0 fsm;
Transport transport;
int seat;
vector position;
void eAI_Vehicles_GoTo_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GoTo_State_0";
m_Name = "GoTo";
}
override void OnEntry(string Event, eAIState From) {
auto group = unit.GetGroup();	
auto leader = group.GetLeader();	
Class.CastTo(transport, leader.GetParent());	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
vector direction;	
transport.CrewEntryWS(seat, position, direction);
unit.OverrideTargetPosition(position);
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Vehicles_GetIn_OpenDoor_State_0 extends eAIState {
eAI_Vehicles_FSM_0 fsm;
CarScript transport;
int seat;
bool hasDoor;
string source;
vector position;
void eAI_Vehicles_GetIn_OpenDoor_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetIn_OpenDoor_State_0";
m_Name = "GetIn_OpenDoor";
}
override void OnEntry(string Event, eAIState From) {
ExpansionFSMHelper.DoorAnimationSource(transport, seat, hasDoor, source);	
if (hasDoor)	
{	
transport.SetAnimationPhase(source, 1.0);	
}	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!hasDoor) return EXIT;
vector direction;	
transport.CrewEntryWS(seat, position, direction);
unit.OverrideTargetPosition(position);	
if (transport && transport.GetAnimationPhase(source) <= 0.5) return CONTINUE;	
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Vehicles_GetIn_CloseDoor_State_0 extends eAIState {
eAI_Vehicles_FSM_0 fsm;
CarScript transport;
int seat;
bool hasDoor;
string source;
vector position;
void eAI_Vehicles_GetIn_CloseDoor_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetIn_CloseDoor_State_0";
m_Name = "GetIn_CloseDoor";
}
override void OnEntry(string Event, eAIState From) {
ExpansionFSMHelper.DoorAnimationSource(transport, seat, hasDoor, source);	
if (hasDoor) transport.SetAnimationPhase(source, 0.0);	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!hasDoor) return EXIT;	
vector direction;	
transport.CrewEntryWS(seat, position, direction);
unit.OverrideTargetPosition(position);
if (transport && transport.GetAnimationPhase(source) >= 0.5) return CONTINUE;	
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Vehicles_GetIn_State_0 extends eAIState {
eAI_Vehicles_FSM_0 fsm;
Transport transport;
int seat;
vector position;
void eAI_Vehicles_GetIn_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetIn_State_0";
m_Name = "GetIn";
}
override void OnEntry(string Event, eAIState From) {
auto group = unit.GetGroup();	
auto leader = group.GetLeader();	
Class.CastTo(transport, leader.GetParent());
unit.Notify_Transport(transport, seat);	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
vector direction;	
transport.CrewEntryWS(seat, position, direction);
unit.OverrideTargetPosition(position);	
auto vehCmd = unit.GetCommand_VehicleAI();	
if (vehCmd && vehCmd.IsGettingIn()) return CONTINUE;
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Vehicles_Sitting_State_0 extends eAIState {
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_Sitting_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_Sitting_State_0";
m_Name = "Sitting";
}
override void OnEntry(string Event, eAIState From) {

}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Vehicles_GetOut_OpenDoor_State_0 extends eAIState {
eAI_Vehicles_FSM_0 fsm;
Object object;
CarScript transport;
int seat;
bool hasDoor;
string source;
void eAI_Vehicles_GetOut_OpenDoor_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetOut_OpenDoor_State_0";
m_Name = "GetOut_OpenDoor";
}
override void OnEntry(string Event, eAIState From) {
seat = unit.GetCommand_VehicleAI().GetVehicleSeat();	
object = unit.GetCommand_VehicleAI().GetObject();	
if (Class.CastTo(transport, object))	
{	
ExpansionFSMHelper.DoorAnimationSource(transport, seat, hasDoor, source);	
if (hasDoor) transport.SetAnimationPhase(source, 1.0);	
}	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!hasDoor) return EXIT;	
unit.OverrideTargetPosition(unit.GetPosition());
if (transport && transport.GetAnimationPhase(source) <= 0.5) return CONTINUE;	
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Vehicles_GetOut_CloseDoor_State_0 extends eAIState {
eAI_Vehicles_FSM_0 fsm;
Object object;
CarScript transport;
int seat;
bool hasDoor;
string source;
void eAI_Vehicles_GetOut_CloseDoor_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetOut_CloseDoor_State_0";
m_Name = "GetOut_CloseDoor";
}
override void OnEntry(string Event, eAIState From) {
seat = unit.GetCommand_VehicleAI().GetVehicleSeat();	
object = unit.GetCommand_VehicleAI().GetObject();	
if (Class.CastTo(transport, object))	
{	
ExpansionFSMHelper.DoorAnimationSource(transport, seat, hasDoor, source);	
if (hasDoor) transport.SetAnimationPhase(source, 0.0);	
}	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!hasDoor) return EXIT;	
unit.OverrideTargetPosition(unit.GetPosition());
if (transport && transport.GetAnimationPhase(source) >= 0.5) return CONTINUE;	
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Vehicles_GetOut_State_0 extends eAIState {
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_GetOut_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetOut_State_0";
m_Name = "GetOut";
}
override void OnEntry(string Event, eAIState From) {
unit.GetCommand_VehicleAI().GetOutVehicle();	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
unit.OverrideTargetPosition(unit.GetPosition());
auto vehCmd = unit.GetCommand_VehicleAI();	
if (vehCmd && vehCmd.IsGettingOut()) return CONTINUE;	
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Vehicles_GoTo__Transition_0 extends eAITransition {
private eAI_Vehicles_GoTo_State_0 src;
private eAIState dst;
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_GoTo__Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GoTo__Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Vehicles_GoTo_State_0"));
Class.CastTo(dst, _fsm.GetState("eAIState"));
}
override int Guard() {
auto group = unit.GetGroup(); 
if (!group) return SUCCESS;
auto leader = group.GetLeader(); 
if (!leader || leader == unit) return SUCCESS;	
if (group.GetFormationState() == eAIGroupFormationState.IN && leader.IsInTransport()) 	
{	
Transport transport;	
if (!Class.CastTo(transport, leader.GetParent())) return SUCCESS;
//TODO: make this event based instead and store as a variable within CarScript.	
//Prevents looping through the crew and insteads just compares a bool.	
for (int i = 1; i < transport.CrewSize(); i++)	
{	
if (transport.CrewMember(i) == null)	
{	
src.seat = i;	
return FAIL;	
}	
}	
}
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Vehicles_GoTo_GetIn_OpenDoor_Transition_0 extends eAITransition {
private eAI_Vehicles_GoTo_State_0 src;
private eAI_Vehicles_GetIn_OpenDoor_State_0 dst;
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_GoTo_GetIn_OpenDoor_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GoTo_GetIn_OpenDoor_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Vehicles_GoTo_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Vehicles_GetIn_OpenDoor_State_0"));
}
override int Guard() {
dst.transport = src.transport;	
dst.seat = src.seat;	
dst.position = src.position;
if (vector.Distance(unit.GetPosition(), dst.position) > 0.5) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Vehicles_GetIn_OpenDoor_GetIn_Transition_0 extends eAITransition {
private eAI_Vehicles_GetIn_OpenDoor_State_0 src;
private eAI_Vehicles_GetIn_State_0 dst;
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_GetIn_OpenDoor_GetIn_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetIn_OpenDoor_GetIn_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Vehicles_GetIn_OpenDoor_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Vehicles_GetIn_State_0"));
}
override int Guard() {
dst.transport = src.transport;	
dst.seat = src.seat;	
dst.position = src.position;
if (vector.Distance(unit.GetPosition(), dst.position) > 0.5) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Vehicles_GetIn_GetIn_CloseDoor_Transition_0 extends eAITransition {
private eAI_Vehicles_GetIn_State_0 src;
private eAI_Vehicles_GetIn_CloseDoor_State_0 dst;
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_GetIn_GetIn_CloseDoor_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetIn_GetIn_CloseDoor_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Vehicles_GetIn_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Vehicles_GetIn_CloseDoor_State_0"));
}
override int Guard() {
dst.transport = src.transport;	
dst.seat = src.seat;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Vehicles_GetIn_CloseDoor_Sitting_Transition_0 extends eAITransition {
private eAI_Vehicles_GetIn_CloseDoor_State_0 src;
private eAI_Vehicles_Sitting_State_0 dst;
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_GetIn_CloseDoor_Sitting_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetIn_CloseDoor_Sitting_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Vehicles_GetIn_CloseDoor_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Vehicles_Sitting_State_0"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Vehicles_Sitting_GetOut_OpenDoor_Transition_0 extends eAITransition {
private eAI_Vehicles_Sitting_State_0 src;
private eAI_Vehicles_GetOut_OpenDoor_State_0 dst;
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_Sitting_GetOut_OpenDoor_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_Sitting_GetOut_OpenDoor_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Vehicles_Sitting_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Vehicles_GetOut_OpenDoor_State_0"));
}
override int Guard() {
auto group = unit.GetGroup(); 
if (!group) return SUCCESS;
auto leader = group.GetLeader(); 
if (!leader || leader == unit) return SUCCESS;	
if (group.GetFormationState() == eAIGroupFormationState.IN && leader.IsInTransport()) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Vehicles_GetOut_OpenDoor_GetOut_Transition_0 extends eAITransition {
private eAI_Vehicles_GetOut_OpenDoor_State_0 src;
private eAI_Vehicles_GetOut_State_0 dst;
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_GetOut_OpenDoor_GetOut_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetOut_OpenDoor_GetOut_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Vehicles_GetOut_OpenDoor_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Vehicles_GetOut_State_0"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Vehicles_GetOut_GetOut_CloseDoor_Transition_0 extends eAITransition {
private eAI_Vehicles_GetOut_State_0 src;
private eAI_Vehicles_GetOut_CloseDoor_State_0 dst;
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_GetOut_GetOut_CloseDoor_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetOut_GetOut_CloseDoor_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Vehicles_GetOut_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Vehicles_GetOut_CloseDoor_State_0"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Vehicles_GetOut_CloseDoor__Transition_0 extends eAITransition {
private eAI_Vehicles_GetOut_CloseDoor_State_0 src;
private eAIState dst;
eAI_Vehicles_FSM_0 fsm;
void eAI_Vehicles_GetOut_CloseDoor__Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Vehicles_GetOut_CloseDoor__Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Vehicles_GetOut_CloseDoor_State_0"));
Class.CastTo(dst, _fsm.GetState("eAIState"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Vehicles_FSM_0 extends eAIFSM {
void eAI_Vehicles_FSM_0(eAIBase unit, eAIState parentState) {
m_Name = "Vehicles";
m_DefaultState = "eAI_Vehicles_GoTo_State_0";
Setup();
SortTransitions();
}
void Setup() {
AddState(new eAI_Vehicles_GoTo_State_0(this, m_Unit));
AddState(new eAI_Vehicles_GetIn_OpenDoor_State_0(this, m_Unit));
AddState(new eAI_Vehicles_GetIn_CloseDoor_State_0(this, m_Unit));
AddState(new eAI_Vehicles_GetIn_State_0(this, m_Unit));
AddState(new eAI_Vehicles_Sitting_State_0(this, m_Unit));
AddState(new eAI_Vehicles_GetOut_OpenDoor_State_0(this, m_Unit));
AddState(new eAI_Vehicles_GetOut_CloseDoor_State_0(this, m_Unit));
AddState(new eAI_Vehicles_GetOut_State_0(this, m_Unit));
AddTransition(new eAI_Vehicles_GoTo__Transition_0(this, m_Unit));
AddTransition(new eAI_Vehicles_GoTo_GetIn_OpenDoor_Transition_0(this, m_Unit));
AddTransition(new eAI_Vehicles_GetIn_OpenDoor_GetIn_Transition_0(this, m_Unit));
AddTransition(new eAI_Vehicles_GetIn_GetIn_CloseDoor_Transition_0(this, m_Unit));
AddTransition(new eAI_Vehicles_GetIn_CloseDoor_Sitting_Transition_0(this, m_Unit));
AddTransition(new eAI_Vehicles_Sitting_GetOut_OpenDoor_Transition_0(this, m_Unit));
AddTransition(new eAI_Vehicles_GetOut_OpenDoor_GetOut_Transition_0(this, m_Unit));
AddTransition(new eAI_Vehicles_GetOut_GetOut_CloseDoor_Transition_0(this, m_Unit));
AddTransition(new eAI_Vehicles_GetOut_CloseDoor__Transition_0(this, m_Unit));
}
}
eAIFSM Create_eAI_Vehicles_FSM_0(eAIBase unit, eAIState parentState) {
return new eAI_Vehicles_FSM_0(unit, parentState);
}
class eAI_Fighting_Positioning_State_0 extends eAIState {
eAI_Fighting_FSM_0 fsm;
vector position;
float time;
float movementDirection;
void eAI_Fighting_Positioning_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Fighting_Positioning_State_0";
m_Name = "Positioning";
}
override void OnEntry(string Event, eAIState From) {
time = 0;	
}
override void OnExit(string Event, bool Aborted, eAIState To) {
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
bool wantsLower = false;	
bool wantsRaise = false;
if (GetGame().GetTime() - fsm.LastFireTime > fsm.TimeBetweenFiring)	
{	
wantsLower = true;	
}
auto target = unit.GetTarget();	
if (target)	
{	
position = target.GetPosition(unit);	
auto aimPosition = position + target.GetAimOffset(unit);	
auto distanceSq = vector.DistanceSq(unit.GetPosition(), position);	
bool shouldBeMeleeing = false;
auto hands = unit.GetHumanInventory().GetEntityInHands();	
if (!hands)	
{	
shouldBeMeleeing = true;	
}	
else if (hands.IsWeapon())	
{	
if (distanceSq <= 2.25)	
{	
shouldBeMeleeing = true;	
}	
}	
else if (hands.IsMeleeWeapon())	
{	
shouldBeMeleeing = true;	
}	
if (shouldBeMeleeing)	
{	
if (distanceSq <= 4.0)	
{	
wantsRaise = true;	
}	
else	
{	
wantsLower = true;	
}	
}
if (distanceSq <= 1.0)	
{	
time += DeltaTime;	
//unit.OverrideStance(DayZPlayerConstants.STANCEIDX_RAISEDERECT);	
if (!movementDirection || time > Math.RandomIntInclusive(1, 3))	
{	
if (Math.RandomIntInclusive(0, 1))	
movementDirection = Math.RandomFloat(135, 180);	
else	
movementDirection = Math.RandomFloat(-135, -180);	
}	
unit.OverrideMovementDirection(true, movementDirection);	
unit.OverrideMovementSpeed(true, Math.RandomIntInclusive(1, 2));	
}	
else	
{	
//unit.OverrideStance(0);	
unit.OverrideMovementDirection(false, 0);	
unit.OverrideMovementSpeed(false, 0);	
time = 0;	
movementDirection= 0;	
}
unit.LookAtPosition(aimPosition);	
unit.AimAtPosition(aimPosition);	
}	
else	
{	
unit.OverrideMovementDirection(false, 0);	
unit.OverrideMovementSpeed(false, 0);	
}
if (wantsRaise && unit.CanRaiseWeapon())	
{	
unit.RaiseWeapon(true);	
}	
else if (wantsLower || !unit.CanRaiseWeapon())	
{	
unit.RaiseWeapon(false);	
}
unit.OverrideTargetPosition(position);
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Fighting_FireWeapon_State_0 extends eAIState {
eAI_Fighting_FSM_0 fsm;
float time;
eAITarget target;
void eAI_Fighting_FireWeapon_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Fighting_FireWeapon_State_0";
m_Name = "FireWeapon";
}
override void OnEntry(string Event, eAIState From) {
unit.RaiseWeapon(true);
time = 0;
fsm.LastFireTime = GetGame().GetTime();	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!target)	
return EXIT;
auto lowPosition = target.GetPosition(unit);	
auto aimPosition = lowPosition + target.GetAimOffset(unit);
time += DeltaTime;	
unit.OverrideTargetPosition(lowPosition);	
unit.LookAtPosition(aimPosition);	
unit.AimAtPosition(aimPosition);
if (!unit.IsRaised() || !unit.IsWeaponRaiseCompleted())	
{	
unit.RaiseWeapon(true);
if (time >= 0.5)	
{	
return EXIT;	
}
// waiting for the weapon to be raised	
return CONTINUE;	
}
unit.TryFireWeapon();
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Fighting_Melee_State_0 extends eAIState {
eAI_Fighting_FSM_0 fsm;
float time;
eAITarget target;
float movementDirection;
void eAI_Fighting_Melee_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Fighting_Melee_State_0";
m_Name = "Melee";
}
override void OnEntry(string Event, eAIState From) {
time = 0;
fsm.LastFireTime = GetGame().GetTime();	
}
override void OnExit(string Event, bool Aborted, eAIState To) {
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!target)	
return EXIT;
auto lowPosition = target.GetPosition(unit);	
auto aimPosition = lowPosition + target.GetAimOffset(unit);
time += DeltaTime;	
unit.OverrideTargetPosition(lowPosition);	
unit.LookAtPosition(aimPosition);	
unit.AimAtPosition(aimPosition);
float distanceSq = target.GetDistanceSq(unit);	
if (distanceSq > 2.25)	
{	
if (time >= 0.5)	
{	
time = 0;	
return EXIT;	
}
return CONTINUE;	
}
auto direction = vector.Direction(unit.GetPosition(), lowPosition).Normalized();	
if (vector.Dot(unit.GetDirection(), direction) < 0.75 || distanceSq <= 1.0)	
{	
if (time >= Math.RandomIntInclusive(1, 3))	
{	
//unit.OverrideStance(0);	
unit.OverrideMovementDirection(false, 0);	
unit.OverrideMovementSpeed(false, 0);	
time = 0;	
movementDirection = 0;	
return EXIT;	
}
//unit.OverrideStance(DayZPlayerConstants.STANCEIDX_RAISEDERECT);	
if (!movementDirection || time > Math.RandomIntInclusive(1, 3))	
{	
if (Math.RandomIntInclusive(0, 1))	
movementDirection = Math.RandomFloat(135, 180);	
else	
movementDirection = Math.RandomFloat(-135, -180);	
}	
unit.OverrideMovementDirection(true, movementDirection);	
unit.OverrideMovementSpeed(true, Math.RandomIntInclusive(1, 2));
return CONTINUE;	
}
if (unit.IsInMelee() && time < 0.3)	
{	
return CONTINUE;	
}
unit.Notify_Melee();	
time = 0;	
movementDirection = 0;	
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Fighting__Melee_Transition_0 extends eAITransition {
private eAIState src;
private eAI_Fighting_Melee_State_0 dst;
eAI_Fighting_FSM_0 fsm;
void eAI_Fighting__Melee_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Fighting__Melee_Transition_0";
Class.CastTo(src, _fsm.GetState("eAIState"));
Class.CastTo(dst, _fsm.GetState("eAI_Fighting_Melee_State_0"));
}
override int Guard() {
// we are targetting an entity?	
dst.target = unit.GetTarget();	
if (!dst.target || !dst.target.IsMeleeViable(unit)) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Fighting__FireWeapon_Transition_0 extends eAITransition {
private eAIState src;
private eAI_Fighting_FireWeapon_State_0 dst;
eAI_Fighting_FSM_0 fsm;
void eAI_Fighting__FireWeapon_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Fighting__FireWeapon_Transition_0";
Class.CastTo(src, _fsm.GetState("eAIState"));
Class.CastTo(dst, _fsm.GetState("eAI_Fighting_FireWeapon_State_0"));
}
override int Guard() {
// we are aiming at something?	
dst.target = unit.GetTarget();	
if (!dst.target) return FAIL;
if (unit.IsInMelee()) return FAIL;
// we are holding a weapon	
Weapon weapon;	
if (!Class.CastTo(weapon, unit.GetItemInHands())) return FAIL;
// CanRaiseWeapon will return false if there is no line of sight	
if (!unit.CanRaiseWeapon()) return FAIL;	
int mi = weapon.GetCurrentMuzzle();	
if (weapon.IsChamberEmpty(mi)) return FAIL;	
if (weapon.IsChamberFiredOut(mi)) return FAIL;	
if (weapon.IsChamberJammed(mi)) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Fighting__Positioning_Transition_0 extends eAITransition {
private eAIState src;
private eAI_Fighting_Positioning_State_0 dst;
eAI_Fighting_FSM_0 fsm;
void eAI_Fighting__Positioning_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Fighting__Positioning_Transition_0";
Class.CastTo(src, _fsm.GetState("eAIState"));
Class.CastTo(dst, _fsm.GetState("eAI_Fighting_Positioning_State_0"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Fighting_FSM_0 extends eAIFSM {
int LastFireTime;
int TimeBetweenFiring = 5000;
void eAI_Fighting_FSM_0(eAIBase unit, eAIState parentState) {
m_Name = "Fighting";
m_DefaultState = "eAI_Fighting_Positioning_State_0";
Setup();
SortTransitions();
}
void Setup() {
AddState(new eAI_Fighting_Positioning_State_0(this, m_Unit));
AddState(new eAI_Fighting_FireWeapon_State_0(this, m_Unit));
AddState(new eAI_Fighting_Melee_State_0(this, m_Unit));
AddTransition(new eAI_Fighting__Melee_Transition_0(this, m_Unit));
AddTransition(new eAI_Fighting__FireWeapon_Transition_0(this, m_Unit));
AddTransition(new eAI_Fighting__Positioning_Transition_0(this, m_Unit));
}
}
eAIFSM Create_eAI_Fighting_FSM_0(eAIBase unit, eAIState parentState) {
return new eAI_Fighting_FSM_0(unit, parentState);
}
class eAI_Reloading_Start_State_0 extends eAIState {
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Start_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Start_State_0";
m_Name = "Start";
}
override void OnEntry(string Event, eAIState From) {
fsm.last_attempt_time = GetGame().GetTime();	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Reloading_Reloading_State_0 extends eAIState {
eAI_Reloading_FSM_0 fsm;
Magazine magazine;
void eAI_Reloading_Reloading_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Reloading_State_0";
m_Name = "Reloading";
}
override void OnEntry(string Event, eAIState From) {
unit.RaiseWeapon(true);	
unit.ReloadWeaponAI(fsm.weapon, magazine);	
}
override void OnExit(string Event, bool Aborted, eAIState To) {
unit.RaiseWeapon(false);	
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!unit.GetWeaponManager()) return EXIT;
if (unit.GetWeaponManager().IsRunning()) return CONTINUE;
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Reloading_Reloading_Fail_State_0 extends eAIState {
eAI_Reloading_FSM_0 fsm;
float time;
void eAI_Reloading_Reloading_Fail_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Reloading_Fail_State_0";
m_Name = "Reloading_Fail";
}
override void OnEntry(string Event, eAIState From) {
unit.RaiseWeapon(false);
time = 0;	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
time += DeltaTime;
// waiting for the weapon to be lowered	
if (time < 0.5)	
return CONTINUE;
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Reloading_Swapping_Gun_State_0 extends eAIState {
eAI_Reloading_FSM_0 fsm;
ItemBase item;
void eAI_Reloading_Swapping_Gun_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Swapping_Gun_State_0";
m_Name = "Swapping_Gun";
}
override void OnEntry(string Event, eAIState From) {
unit.LocalTakeEntityToHands(item);	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Reloading_Swapping_Melee_State_0 extends eAIState {
eAI_Reloading_FSM_0 fsm;
ItemBase item;
void eAI_Reloading_Swapping_Melee_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Swapping_Melee_State_0";
m_Name = "Swapping_Melee";
}
override void OnEntry(string Event, eAIState From) {
unit.LocalTakeEntityToHands(item);	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Reloading_Removing_State_0 extends eAIState {
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Removing_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Removing_State_0";
m_Name = "Removing";
}
override void OnEntry(string Event, eAIState From) {

}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (unit.GetItemInHands() != fsm.weapon)	
return EXIT;  // remove complete
InventoryLocation il_src = new InventoryLocation();	
InventoryLocation il_dst = new InventoryLocation();
fsm.weapon.GetInventory().GetCurrentInventoryLocation(il_src);
//if (!unit.GetInventory().FindFreeLocationFor(fsm.weapon, FindInventoryLocationType.ATTACHMENT | FindInventoryLocationType.CARGO, il_dst))	
//{	
GameInventory.SetGroundPosByOwner(unit, fsm.weapon, il_dst);	
//}	
unit.ServerTakeToDst(il_src, il_dst);
return CONTINUE; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Reloading_Start_Reloading_Transition_0 extends eAITransition {
private eAI_Reloading_Start_State_0 src;
private eAI_Reloading_Reloading_State_0 dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Start_Reloading_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Start_Reloading_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Start_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Reloading_Reloading_State_0"));
}
override int Guard() {
int mi = fsm.weapon.GetCurrentMuzzle();	
Magazine mag;	
if (fsm.weapon.HasInternalMagazine(mi) && fsm.weapon.GetInternalMagazineCartridgeCount(mi) > 0)	
{	
EXTrace.Start0(EXTrace.AI, this, "Reloading " + fsm.weapon + " from internal mag");	
dst.magazine = null;	
}	
else if (Class.CastTo(mag, fsm.weapon.GetMagazine(mi)) && mag.GetAmmoCount() > 0)	
{	
EXTrace.Start0(EXTrace.AI, this, "Reloading " + fsm.weapon + " from attached mag");	
dst.magazine = mag;	
}	
else	
{	
dst.magazine = unit.GetMagazineToReload(fsm.weapon);	
if (!dst.magazine) return FAIL;	
EXTrace.Start0(EXTrace.AI, this, "Reloading " + fsm.weapon + " from mag " + dst.magazine);	
}	
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_Start_Reloading_Fail_Transition_0 extends eAITransition {
private eAI_Reloading_Start_State_0 src;
private eAI_Reloading_Reloading_Fail_State_0 dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Start_Reloading_Fail_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Start_Reloading_Fail_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Start_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Reloading_Reloading_Fail_State_0"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_Removing_Swapping_Gun_Transition_0 extends eAITransition {
private eAI_Reloading_Removing_State_0 src;
private eAI_Reloading_Swapping_Gun_State_0 dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Removing_Swapping_Gun_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Removing_Swapping_Gun_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Removing_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Reloading_Swapping_Gun_State_0"));
}
override int Guard() {
//! TODO: Fix weapon change in MP	
if (GetGame().IsMultiplayer()) return FAIL;
dst.item = unit.GetWeaponToUse(true);
if (!dst.item) return FAIL; 
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_Removing_Swapping_Melee_Transition_0 extends eAITransition {
private eAI_Reloading_Removing_State_0 src;
private eAI_Reloading_Swapping_Melee_State_0 dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Removing_Swapping_Melee_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Removing_Swapping_Melee_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Removing_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Reloading_Swapping_Melee_State_0"));
}
override int Guard() {
dst.item = unit.GetMeleeWeaponToUse();
if (!dst.item) return FAIL; 
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_Reloading_Fail_Removing_Transition_0 extends eAITransition {
private eAI_Reloading_Reloading_Fail_State_0 src;
private eAI_Reloading_Removing_State_0 dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Reloading_Fail_Removing_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Reloading_Fail_Removing_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Reloading_Fail_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Reloading_Removing_State_0"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_Reloading__Transition_0 extends eAITransition {
private eAI_Reloading_Reloading_State_0 src;
private eAIState dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Reloading__Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Reloading__Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Reloading_State_0"));
Class.CastTo(dst, _fsm.GetState("eAIState"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_Swapping_Gun_Reloading_Transition_0 extends eAITransition {
private eAI_Reloading_Swapping_Gun_State_0 src;
private eAI_Reloading_Reloading_State_0 dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Swapping_Gun_Reloading_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Swapping_Gun_Reloading_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Swapping_Gun_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Reloading_Reloading_State_0"));
}
override int Guard() {
dst.magazine = unit.GetMagazineToReload(fsm.weapon);	
if (!dst.magazine) return FAIL;	
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_Swapping_Gun__Transition_0 extends eAITransition {
private eAI_Reloading_Swapping_Gun_State_0 src;
private eAIState dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Swapping_Gun__Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Swapping_Gun__Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Swapping_Gun_State_0"));
Class.CastTo(dst, _fsm.GetState("eAIState"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_Swapping_Melee__Transition_0 extends eAITransition {
private eAI_Reloading_Swapping_Melee_State_0 src;
private eAIState dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Swapping_Melee__Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Swapping_Melee__Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Swapping_Melee_State_0"));
Class.CastTo(dst, _fsm.GetState("eAIState"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_Removing__Transition_0 extends eAITransition {
private eAI_Reloading_Removing_State_0 src;
private eAIState dst;
eAI_Reloading_FSM_0 fsm;
void eAI_Reloading_Removing__Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Reloading_Removing__Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Reloading_Removing_State_0"));
Class.CastTo(dst, _fsm.GetState("eAIState"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Reloading_FSM_0 extends eAIFSM {
Weapon weapon;
int last_attempt_time;
void eAI_Reloading_FSM_0(eAIBase unit, eAIState parentState) {
m_Name = "Reloading";
m_DefaultState = "eAI_Reloading_Start_State_0";
Setup();
SortTransitions();
}
void Setup() {
AddState(new eAI_Reloading_Start_State_0(this, m_Unit));
AddState(new eAI_Reloading_Reloading_State_0(this, m_Unit));
AddState(new eAI_Reloading_Reloading_Fail_State_0(this, m_Unit));
AddState(new eAI_Reloading_Swapping_Gun_State_0(this, m_Unit));
AddState(new eAI_Reloading_Swapping_Melee_State_0(this, m_Unit));
AddState(new eAI_Reloading_Removing_State_0(this, m_Unit));
AddTransition(new eAI_Reloading_Start_Reloading_Transition_0(this, m_Unit));
AddTransition(new eAI_Reloading_Start_Reloading_Fail_Transition_0(this, m_Unit));
AddTransition(new eAI_Reloading_Removing_Swapping_Gun_Transition_0(this, m_Unit));
AddTransition(new eAI_Reloading_Removing_Swapping_Melee_Transition_0(this, m_Unit));
AddTransition(new eAI_Reloading_Reloading_Fail_Removing_Transition_0(this, m_Unit));
AddTransition(new eAI_Reloading_Reloading__Transition_0(this, m_Unit));
AddTransition(new eAI_Reloading_Swapping_Gun_Reloading_Transition_0(this, m_Unit));
AddTransition(new eAI_Reloading_Swapping_Gun__Transition_0(this, m_Unit));
AddTransition(new eAI_Reloading_Swapping_Melee__Transition_0(this, m_Unit));
AddTransition(new eAI_Reloading_Removing__Transition_0(this, m_Unit));
}
}
eAIFSM Create_eAI_Reloading_FSM_0(eAIBase unit, eAIState parentState) {
return new eAI_Reloading_FSM_0(unit, parentState);
}
class eAI_Master_Idle_State_0 extends eAIState {
eAI_Master_FSM_0 fsm;
float time;
float timeLower;
void eAI_Master_Idle_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Idle_State_0";
m_Name = "Idle";
}
override void OnEntry(string Event, eAIState From) {
time = 0;	
if (unit.IsRaised())	
timeLower = Math.RandomFloat(0.5, 1.5);
if (!unit.GetTarget())	
{	
if (unit.GetLookDirectionRecalculate())	
unit.LookAtDirection("0 0 1");
if (unit.GetAimDirectionRecalculate())	
unit.AimAtDirection("0 0 1");	
}
unit.OverrideMovementDirection(false, 0);	
unit.OverrideMovementSpeed(true, 0);	
unit.Expansion_GetUp();	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!unit.GetTarget())	
{	
time += DeltaTime;
if (unit.IsRaised() && time < timeLower)	
return CONTINUE;
unit.RaiseWeapon(false);	
}	
else if (!unit.CanRaiseWeapon())	
{	
unit.RaiseWeapon(false);	
}
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Master_Unconscious_State_0 extends eAIState {
eAI_Master_FSM_0 fsm;
float time;
void eAI_Master_Unconscious_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Unconscious_State_0";
m_Name = "Unconscious";
}
override void OnEntry(string Event, eAIState From) {
time = 0;	
unit.OverrideTargetPosition(unit.GetPosition());	
}
override void OnExit(string Event, bool Aborted, eAIState To) {
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!unit.IsUnconscious())	
time += DeltaTime;  //! Allow time to stand up so we don't instantly start firing 
return EXIT; 
}
override bool ExitGuard(string Event) {
return !unit.IsUnconscious() && time > 3;	
}
}
class eAI_Master_Trading_State_0 extends eAIState {
eAI_Master_FSM_0 fsm;
void eAI_Master_Trading_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Trading_State_0";
m_Name = "Trading";
}
override void OnEntry(string Event, eAIState From) {
unit.OverrideTargetPosition(unit.GetPosition());	
}
override void OnExit(string Event, bool Aborted, eAIState To) {
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
return EXIT; 
}
override bool ExitGuard(string Event) {
return !(unit.IsTrading());	
}
}
class eAI_Master_FollowFormation_State_0 extends eAIState {
eAI_Master_FSM_0 fsm;
eAIGroup group;
void eAI_Master_FollowFormation_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_FollowFormation_State_0";
m_Name = "FollowFormation";
}
override void OnEntry(string Event, eAIState From) {

}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
unit.OverrideTargetPosition(group.GetFormationPosition(unit));	
unit.OverrideMovementSpeed(false, 0);
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Master_TraversingWaypoints_State_0 extends eAIState {
eAI_Master_FSM_0 fsm;
ref array<vector> path;
eAIWaypointBehavior behaviour;
bool backtracking;
int index;
float threshold = 1.0;
float previousDistance;
void eAI_Master_TraversingWaypoints_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_TraversingWaypoints_State_0";
m_Name = "TraversingWaypoints";
}
override void OnEntry(string Event, eAIState From) {
path = unit.GetGroup().GetWaypoints();	
if (path.Count() == 0)	
{	
path = { unit.GetPosition() };	
}	
behaviour = unit.GetGroup().GetWaypointBehaviour();	
}
override void OnExit(string Event, bool Aborted, eAIState To) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
float distance = vector.DistanceSq(unit.GetPosition(), path[index]);	
if (distance < threshold)	
{	
if (backtracking) index--;	
else index++;	
threshold = 1.0;	
}	
else if (Math.AbsFloat(distance - previousDistance) < 0.01)	
{	
//! We seem to not be getting closer to the waypoint, possibly the path is blocked.	
//! Increase threshold until we are within distance.	
threshold += 0.01;	
}
previousDistance = distance;
if (index < 0) 	
{	
if (behaviour == eAIWaypointBehavior.REVERSE)	
{	
backtracking = false;	
index = 1;	
}	
}	
else if (index == path.Count())	
{	
if (behaviour == eAIWaypointBehavior.REVERSE)	
{	
backtracking = true;	
index = path.Count() - 2;	
} 	
else if (behaviour == eAIWaypointBehavior.LOOP)	
{	
backtracking = false;	
index = 0;	
}	
}
index = Math.Clamp(index, 0, path.Count() - 1);
unit.OverrideTargetPosition(path[index]);	
unit.OverrideMovementSpeed(false, 0);
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Master_Vehicles_State_0 extends eAIState {
eAI_Vehicles_FSM_0 sub_fsm;
eAI_Master_FSM_0 fsm;
void eAI_Master_Vehicles_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Vehicles_State_0";
m_Name = "Vehicles";
m_SubFSM = new eAI_Vehicles_FSM_0(_unit, this);
Class.CastTo(sub_fsm, m_SubFSM);
}
override void OnEntry(string Event, eAIState From) {
if (Event != "") m_SubFSM.Start(Event);
else m_SubFSM.StartDefault();
}
override void OnExit(string Event, bool Aborted, eAIState To) {
if (Aborted) m_SubFSM.Abort(Event);
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (m_SubFSM.Update(DeltaTime, SimulationPrecision) == EXIT) return EXIT;
return CONTINUE;
}
override bool ExitGuard(string Event) {
if (!m_SubFSM.ExitGuard(Event)) return false;
return true;
}
}
class eAI_Master_Fighting_State_0 extends eAIState {
eAI_Fighting_FSM_0 sub_fsm;
eAI_Master_FSM_0 fsm;
void eAI_Master_Fighting_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Fighting_State_0";
m_Name = "Fighting";
m_SubFSM = new eAI_Fighting_FSM_0(_unit, this);
Class.CastTo(sub_fsm, m_SubFSM);
}
override void OnEntry(string Event, eAIState From) {
if (Event != "") m_SubFSM.Start(Event);
else m_SubFSM.StartDefault();
unit.UpdateAimArbitration();	
}
override void OnExit(string Event, bool Aborted, eAIState To) {
if (Aborted) m_SubFSM.Abort(Event);
unit.StopAimArbitration();	
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (m_SubFSM.Update(DeltaTime, SimulationPrecision) == EXIT) return EXIT;
return EXIT; 
}
override bool ExitGuard(string Event) {
if (!m_SubFSM.ExitGuard(Event)) return false;
return true;
}
}
class eAI_Master_Weapon_Reloading_State_0 extends eAIState {
eAI_Reloading_FSM_0 sub_fsm;
eAI_Master_FSM_0 fsm;
void eAI_Master_Weapon_Reloading_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Weapon_Reloading_State_0";
m_Name = "Reloading";
m_SubFSM = new eAI_Reloading_FSM_0(_unit, this);
Class.CastTo(sub_fsm, m_SubFSM);
}
override void OnEntry(string Event, eAIState From) {
if (Event != "") m_SubFSM.Start(Event);
else m_SubFSM.StartDefault();
unit.UpdateAimArbitration();	
}
override void OnExit(string Event, bool Aborted, eAIState To) {
if (Aborted) m_SubFSM.Abort(Event);
unit.StopAimArbitration();	
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (m_SubFSM.Update(DeltaTime, SimulationPrecision) == EXIT) return EXIT;
return CONTINUE;
}
override bool ExitGuard(string Event) {
if (!m_SubFSM.ExitGuard(Event)) return false;
return true;
}
}
class eAI_Master_Weapon_Unjamming_State_0 extends eAIState {
eAI_Master_FSM_0 fsm;
Weapon_Base weapon;
void eAI_Master_Weapon_Unjamming_State_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Weapon_Unjamming_State_0";
m_Name = "Weapon_Unjamming";
}
override void OnEntry(string Event, eAIState From) {
unit.RaiseWeapon(true);
unit.StartActionObject(eAIActionWeaponUnjam, null);	
}
override void OnExit(string Event, bool Aborted, eAIState To) {
unit.RaiseWeapon(false);	
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!unit.GetWeaponManager()) return EXIT;
if (unit.GetWeaponManager().IsRunning()) return CONTINUE;
return EXIT; 
}
override bool ExitGuard(string Event) {
return true;
}
}
class eAI_Master__Unconscious_Transition_0 extends eAITransition {
private eAIState src;
private eAI_Master_Unconscious_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master__Unconscious_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master__Unconscious_Transition_0";
Class.CastTo(src, _fsm.GetState("eAIState"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Unconscious_State_0"));
}
override int Guard() {
if (!(unit.IsUnconscious())) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_Unconscious_Idle_Transition_0 extends eAITransition {
private eAI_Master_Unconscious_State_0 src;
private eAI_Master_Idle_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_Unconscious_Idle_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Unconscious_Idle_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_Unconscious_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Idle_State_0"));
}
override int Guard() {
if (unit.IsUnconscious()) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master__Trading_Transition_0 extends eAITransition {
private eAIState src;
private eAI_Master_Trading_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master__Trading_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master__Trading_Transition_0";
Class.CastTo(src, _fsm.GetState("eAIState"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Trading_State_0"));
}
override int Guard() {
if (!(unit.IsTrading())) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_Trading_Idle_Transition_0 extends eAITransition {
private eAI_Master_Trading_State_0 src;
private eAI_Master_Idle_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_Trading_Idle_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Trading_Idle_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_Trading_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Idle_State_0"));
}
override int Guard() {
if (unit.IsTrading()) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_Idle_FollowFormation_Transition_0 extends eAITransition {
private eAI_Master_Idle_State_0 src;
private eAI_Master_FollowFormation_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_Idle_FollowFormation_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Idle_FollowFormation_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_Idle_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_FollowFormation_State_0"));
}
override int Guard() {
if (unit.GetThreatToSelf() > 0.4) return FAIL;
dst.group = unit.GetGroup(); 
if (!dst.group) return FAIL;
if (dst.group.GetFormationState() != eAIGroupFormationState.IN) return FAIL;
auto leader = dst.group.GetLeader(); 
if (!leader || leader == unit) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_Idle_TraversingWaypoints_Transition_0 extends eAITransition {
private eAI_Master_Idle_State_0 src;
private eAI_Master_TraversingWaypoints_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_Idle_TraversingWaypoints_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Idle_TraversingWaypoints_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_Idle_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_TraversingWaypoints_State_0"));
}
override int Guard() {
if (unit.GetThreatToSelf() > 0.4) return FAIL;
auto group = unit.GetGroup(); 
if (!group) return FAIL;
// we are the leader so we traverse the waypoints 
auto leader = group.GetLeader(); 
if (leader && leader != unit) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_TraversingWaypoints_Idle_Transition_0 extends eAITransition {
private eAI_Master_TraversingWaypoints_State_0 src;
private eAI_Master_Idle_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_TraversingWaypoints_Idle_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_TraversingWaypoints_Idle_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_TraversingWaypoints_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Idle_State_0"));
}
override int Guard() {
if (unit.GetThreatToSelf() > 0.4) return SUCCESS;
return FAIL; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_FollowFormation_Idle_Transition_0 extends eAITransition {
private eAI_Master_FollowFormation_State_0 src;
private eAI_Master_Idle_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_FollowFormation_Idle_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_FollowFormation_Idle_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_FollowFormation_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Idle_State_0"));
}
override int Guard() {
auto group = unit.GetGroup();	
if (group && group.GetFormationState() != eAIGroupFormationState.IN) return SUCCESS;	
if (unit.GetThreatToSelf() > 0.4) return SUCCESS;
return FAIL; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master__Weapon_Reloading_Transition_0 extends eAITransition {
private eAIState src;
private eAI_Master_Weapon_Reloading_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master__Weapon_Reloading_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master__Weapon_Reloading_Transition_0";
Class.CastTo(src, _fsm.GetState("eAIState"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Weapon_Reloading_State_0"));
}
override int Guard() {
if (GetGame().GetTime() - dst.sub_fsm.last_attempt_time < 5000) return FAIL;
if (!Class.CastTo(dst.sub_fsm.weapon, unit.GetItemInHands())) return FAIL;
int mi = dst.sub_fsm.weapon.GetCurrentMuzzle();	
bool isChamberEmpty = dst.sub_fsm.weapon.IsChamberEmpty(mi);	
bool isChamberFiredOut = dst.sub_fsm.weapon.IsChamberFiredOut(mi);	
if (!(isChamberFiredOut || isChamberEmpty)) return FAIL;	
if (dst.sub_fsm.weapon.IsChamberJammed(mi)) return FAIL;
// don't move to the state if the action manager is operating	
if (!unit.GetActionManager() || unit.GetActionManager().GetRunningAction()) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master__Weapon_Unjamming_Transition_0 extends eAITransition {
private eAIState src;
private eAI_Master_Weapon_Unjamming_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master__Weapon_Unjamming_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master__Weapon_Unjamming_Transition_0";
Class.CastTo(src, _fsm.GetState("eAIState"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Weapon_Unjamming_State_0"));
}
override int Guard() {
if (!Class.CastTo(dst.weapon, unit.GetItemInHands())) return FAIL;
if (!unit.GetWeaponManager().CanUnjam(dst.weapon)) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_Weapon_Reloading_Idle_Transition_0 extends eAITransition {
private eAI_Master_Weapon_Reloading_State_0 src;
private eAI_Master_Idle_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_Weapon_Reloading_Idle_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Weapon_Reloading_Idle_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_Weapon_Reloading_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Idle_State_0"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_Weapon_Unjamming_Idle_Transition_0 extends eAITransition {
private eAI_Master_Weapon_Unjamming_State_0 src;
private eAI_Master_Idle_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_Weapon_Unjamming_Idle_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Weapon_Unjamming_Idle_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_Weapon_Unjamming_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Idle_State_0"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master__Fighting_Transition_0 extends eAITransition {
private eAIState src;
private eAI_Master_Fighting_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master__Fighting_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master__Fighting_Transition_0";
Class.CastTo(src, _fsm.GetState("eAIState"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Fighting_State_0"));
}
override int Guard() {
if (unit.GetThreatToSelf(true) < 0.4) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_Fighting_Idle_Transition_0 extends eAITransition {
private eAI_Master_Fighting_State_0 src;
private eAI_Master_Idle_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_Fighting_Idle_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Fighting_Idle_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_Fighting_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Idle_State_0"));
}
override int Guard() {
if (unit.GetThreatToSelf() > 0.2) return FAIL;
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master__Vehicles_Transition_0 extends eAITransition {
private eAIState src;
private eAI_Master_Vehicles_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master__Vehicles_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master__Vehicles_Transition_0";
Class.CastTo(src, _fsm.GetState("eAIState"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Vehicles_State_0"));
}
override int Guard() {
auto group = unit.GetGroup(); 
if (!group) return FAIL;
if (group.GetFormationState() != eAIGroupFormationState.IN) return FAIL;
auto leader = group.GetLeader(); 
if (!leader || leader == unit) return FAIL;
if (!leader.IsInTransport()) return FAIL;
Transport transport; 
if (!Class.CastTo(transport, leader.GetParent())) return FAIL;
//TODO: make this event based instead and store as a variable within CarScript.	
//Prevents looping through the crew and insteads just compares a bool.	
for (int i = 1; i < transport.CrewSize(); i++)	
{	
if (transport.CrewMember(i) == null)	
{ 
return SUCCESS;	
}	
}
return FAIL; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_Vehicles_Idle_Transition_0 extends eAITransition {
private eAI_Master_Vehicles_State_0 src;
private eAI_Master_Idle_State_0 dst;
eAI_Master_FSM_0 fsm;
void eAI_Master_Vehicles_Idle_Transition_0(eAIFSM _fsm, eAIBase _unit) {
Class.CastTo(fsm, _fsm);
m_ClassName = "eAI_Master_Vehicles_Idle_Transition_0";
Class.CastTo(src, _fsm.GetState("eAI_Master_Vehicles_State_0"));
Class.CastTo(dst, _fsm.GetState("eAI_Master_Idle_State_0"));
}
override int Guard() {
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
class eAI_Master_FSM_0 extends eAIFSM {
void eAI_Master_FSM_0(eAIBase unit, eAIState parentState) {
m_Name = "Master";
m_DefaultState = "eAI_Master_Idle_State_0";
Setup();
SortTransitions();
}
void Setup() {
AddState(new eAI_Master_Idle_State_0(this, m_Unit));
AddState(new eAI_Master_Unconscious_State_0(this, m_Unit));
AddState(new eAI_Master_Trading_State_0(this, m_Unit));
AddState(new eAI_Master_FollowFormation_State_0(this, m_Unit));
AddState(new eAI_Master_TraversingWaypoints_State_0(this, m_Unit));
AddState(new eAI_Master_Vehicles_State_0(this, m_Unit));
AddState(new eAI_Master_Fighting_State_0(this, m_Unit));
AddState(new eAI_Master_Weapon_Reloading_State_0(this, m_Unit));
AddState(new eAI_Master_Weapon_Unjamming_State_0(this, m_Unit));
AddTransition(new eAI_Master__Unconscious_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_Unconscious_Idle_Transition_0(this, m_Unit));
AddTransition(new eAI_Master__Trading_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_Trading_Idle_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_Idle_FollowFormation_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_Idle_TraversingWaypoints_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_TraversingWaypoints_Idle_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_FollowFormation_Idle_Transition_0(this, m_Unit));
AddTransition(new eAI_Master__Weapon_Reloading_Transition_0(this, m_Unit));
AddTransition(new eAI_Master__Weapon_Unjamming_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_Weapon_Reloading_Idle_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_Weapon_Unjamming_Idle_Transition_0(this, m_Unit));
AddTransition(new eAI_Master__Fighting_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_Fighting_Idle_Transition_0(this, m_Unit));
AddTransition(new eAI_Master__Vehicles_Transition_0(this, m_Unit));
AddTransition(new eAI_Master_Vehicles_Idle_Transition_0(this, m_Unit));
}
}
eAIFSM Create_eAI_Master_FSM_0(eAIBase unit, eAIState parentState) {
return new eAI_Master_FSM_0(unit, parentState);
}
