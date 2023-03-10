/*----- PROTECTED REGION ID(DeviceB.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        DeviceB.cpp
//
// description : C++ source for the DeviceB class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               DeviceB are implemented in this file.
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <DeviceB.h>
#include <DeviceBClass.h>

/*----- PROTECTED REGION END -----*/	//	DeviceB.cpp

/**
 *  DeviceB class description:
 *    
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//================================================================
//  State         |  Inherited (no method)
//  Status        |  Inherited (no method)
//  MeasureTemp   |  measure_temp
//================================================================

//================================================================
//  Attributes managed are:
//================================================================
//  Temperature_B1  |  Tango::DevDouble	Scalar
//  Temperature_B2  |  Tango::DevDouble	Scalar
//================================================================

namespace DeviceB_ns
{
/*----- PROTECTED REGION ID(DeviceB::namespace_starting) ENABLED START -----*/

//	static initializations

/*----- PROTECTED REGION END -----*/	//	DeviceB::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : DeviceB::DeviceB()
 *	Description : Constructors for a Tango device
 *                implementing the classDeviceB
 */
//--------------------------------------------------------
DeviceB::DeviceB(Tango::DeviceClass *cl, string &s)
 : TANGO_BASE_CLASS(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(DeviceB::constructor_1) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::constructor_1
}
//--------------------------------------------------------
DeviceB::DeviceB(Tango::DeviceClass *cl, const char *s)
 : TANGO_BASE_CLASS(cl, s)
{
	/*----- PROTECTED REGION ID(DeviceB::constructor_2) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::constructor_2
}
//--------------------------------------------------------
DeviceB::DeviceB(Tango::DeviceClass *cl, const char *s, const char *d)
 : TANGO_BASE_CLASS(cl, s, d)
{
	/*----- PROTECTED REGION ID(DeviceB::constructor_3) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : DeviceB::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void DeviceB::delete_device()
{
	DEBUG_STREAM << "DeviceB::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(DeviceB::delete_device) ENABLED START -----*/
	
	//	Delete device allocated objects
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::delete_device
	delete[] attr_Temperature_B1_read;
	delete[] attr_Temperature_B2_read;
}

//--------------------------------------------------------
/**
 *	Method      : DeviceB::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void DeviceB::init_device()
{
	DEBUG_STREAM << "DeviceB::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(DeviceB::init_device_before) ENABLED START -----*/
	
	//	Initialization before get_device_property() call
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::init_device_before
	
	//	No device property to be read from database
	
	attr_Temperature_B1_read = new Tango::DevDouble[1];
	attr_Temperature_B2_read = new Tango::DevDouble[1];
	/*----- PROTECTED REGION ID(DeviceB::init_device) ENABLED START -----*/
	
	//	Initialize device
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::init_device
}


//--------------------------------------------------------
/**
 *	Method      : DeviceB::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void DeviceB::always_executed_hook()
{
	DEBUG_STREAM << "DeviceB::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(DeviceB::always_executed_hook) ENABLED START -----*/
	
	//	code always executed before all requests
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : DeviceB::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void DeviceB::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "DeviceB::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(DeviceB::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::read_attr_hardware
}

//--------------------------------------------------------
/**
 *	Read attribute Temperature_B1 related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void DeviceB::read_Temperature_B1(Tango::Attribute &attr)
{
	DEBUG_STREAM << "DeviceB::read_Temperature_B1(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(DeviceB::read_Temperature_B1) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_Temperature_B1_read);
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::read_Temperature_B1
}
//--------------------------------------------------------
/**
 *	Read attribute Temperature_B2 related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void DeviceB::read_Temperature_B2(Tango::Attribute &attr)
{
	DEBUG_STREAM << "DeviceB::read_Temperature_B2(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(DeviceB::read_Temperature_B2) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_Temperature_B2_read);
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::read_Temperature_B2
}

//--------------------------------------------------------
/**
 *	Method      : DeviceB::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void DeviceB::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(DeviceB::add_dynamic_attributes) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command MeasureTemp related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void DeviceB::measure_temp()
{
	DEBUG_STREAM << "DeviceB::MeasureTemp()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(DeviceB::measure_temp) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::measure_temp
}
//--------------------------------------------------------
/**
 *	Method      : DeviceB::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void DeviceB::add_dynamic_commands()
{
	/*----- PROTECTED REGION ID(DeviceB::add_dynamic_commands) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic commands if any
	
	/*----- PROTECTED REGION END -----*/	//	DeviceB::add_dynamic_commands
}

/*----- PROTECTED REGION ID(DeviceB::namespace_ending) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	DeviceB::namespace_ending
} //	namespace
