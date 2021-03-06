#include "MecanumSaucerDrive.h"
#include <math.h>

MecanumSaucerDrive::MecanumSaucerDrive(ADIS16448_IMU *imu)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain);
	gyro = imu;
	gyro_angle = 0.0;
}

// Called just before this Command runs the first time
void MecanumSaucerDrive::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void MecanumSaucerDrive::Execute()
{
	if (gyro != nullptr)
	{
		if (oi->xboxBackBtn->Get())
			gyro->Reset();
		else
			gyro_angle = gyro->GetAngleZ();
	}
	// Engage!!!
	// Fourth argument is Saucer Angle which is the negative of the gyro angle.
	drivetrain->Go(this->GetX(), this->GetInvertedY(), this->GetTwist(), -gyro_angle);
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumSaucerDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MecanumSaucerDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumSaucerDrive::Interrupted()
{

}

double MecanumSaucerDrive::GetX()
{
	return oi->xboxController->GetRawAxis(0); // Left stick, X axis
}

double MecanumSaucerDrive::GetY()
{
	return oi->xboxController->GetRawAxis(1); // Left Stick, Y axis
}

double MecanumSaucerDrive::GetInvertedY()
{
	return -oi->xboxController->GetRawAxis(1); // Left Stick, Y axis, Inverted
}

double MecanumSaucerDrive::GetTwist()
{
	return oi->xboxController->GetRawAxis(4); // Right stick, X axis
}

