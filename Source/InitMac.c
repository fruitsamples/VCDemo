/*	InitMac.c	Initialize application environment.	� 1995 Apple Computer, Inc.*/#include <OSUtils.h>#include <QuickDraw.h>#include <Fonts.h>#include <Windows.h>#include <Menus.h>#include <TextEdit.h>#include <Events.h>#include <Dialogs.h>#include <Memory.h>#include "EventLoop.h"#define	_Unimplemented 0xA89F#define	_WaitNextEvent 0xA860Boolean TrapAvailable ( short tNum, short tType);void InitToolBox(short numberOfMasters);Boolean WNEIsImplemented( void );Boolean TrapAvailable ( short tNum, short tType){	return ( NGetTrapAddress(tNum,tType) != GetToolTrapAddress(_Unimplemented) );}Boolean WNEIsImplemented( void ){	SysEnvRec	theWorld;		SysEnvirons(1, &theWorld);	if (theWorld.machineType < 0)		return false;	else		return TrapAvailable ( _WaitNextEvent, ToolTrap);}void InitToolBox(short numberOfMasters){	InitGraf(&qd.thePort);	InitFonts();	InitWindows();	InitMenus();	InitCursor();	TEInit();	FlushEvents(everyEvent, 0);	InitDialogs(0L);		while(numberOfMasters--)		MoreMasters();			MaxApplZone();	WNE_available = WNEIsImplemented();}/* EOF */