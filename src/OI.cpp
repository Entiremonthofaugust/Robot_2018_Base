/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <Commands/GearLight.h>
#include <Commands/PistonExtend.h>
#include <Commands/PistonRetract.h>

/* ****
 *
 * 	xBox Controller button mapping:
 * 	Button 1 - A
 * 	Button 2 - B
 * 	Button 3 - X
 * 	Button 4 - Y
 * 	Button 5 - Left Bumper
 * 	Button 6 - Right Bumper
 * 	Button 7 - Back
 * 	Button 8 - Start
 * 	Button 9 - Left Stick
 * 	Button 10 - Right Stick
 */
OI::OI() {
	// Process operator interface input here.

	// Driver Station USB slot 4: Xbox controller
	xboxController = new Joystick(4);
	// Green light from SteamWorks "Gear Ready"
	// gearLightBtn = new JoystickButton(xboxController, 1);
	// gearLightBtn->WhileHeld(new GearLight);

	// Piston Extend & Retract buttons
	extendBtn = new JoystickButton(xboxController, 7);
	extendBtn->WhenPressed(new PistonExtend);
	retractBtn = new JoystickButton(xboxController, 8);
	retractBtn->WhenPressed(new PistonRetract);

	// PowerCube Grab
	lBumper = new JoystickButton(xboxController, 5);
	lBumper->WhileHeld(new GearLight); // FIXME: replace WhileHeld(new GrabLeft) command
	rBumper = new JoystickButton(xboxController, 6);
	rBumper->WhileHeld(new GearLight); // FIXME: replace with WhenHeld(new GrabRight) command

	// PowerCube Eject
	xboxXBtn = new JoystickButton(xboxController, 3);
	xboxXBtn->WhileHeld(new GearLight); // FIXME: Replace with WhileHeld(new EjectCube) command

	// Climb & Descend
	xboxABtn = new JoystickButton(xboxController, 2);
	xboxABtn->WhileHeld(new GearLight); // FIXME: replace with WhileHeld(new Climb) command
	xboxBBtn = new JoystickButton(xboxController, 1);
	xboxBBtn->WhileHeld(new GearLight); // FIXME: replace with WhileHeld(new Descend) command

	// ForkLift Raise & Lower utilize AXES 2 & 3 (Left & Right Triggers)

	// Initialize the Co-Driver's controller in USB slot 5
	NESController = new Joystick(5);

}
