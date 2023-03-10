/*----- PROTECTED REGION ID(BaslerCamera.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        BaslerCamera.cpp
//
// description : C++ source for the BaslerCamera class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               BaslerCamera are implemented in this file.
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


#include <BaslerCamera.h>
#include <BaslerCameraClass.h>

/*----- PROTECTED REGION END -----*/	//	BaslerCamera.cpp

/**
 *  BaslerCamera class description:
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
//  GrabImage     |  grab_image
//================================================================

//================================================================
//  Attributes managed are:
//================================================================
//  ExposureTime    |  Tango::DevDouble	Scalar
//  FrameRate       |  Tango::DevDouble	Scalar
//  Gain            |  Tango::DevDouble	Scalar
//  TriggerMode     |  Tango::DevUShort	Scalar
//  BeamProfileImg  |  Tango::DevUShort	Image  ( max = 1280 x 1024)
//================================================================

namespace BaslerCamera_ns
{
/*----- PROTECTED REGION ID(BaslerCamera::namespace_starting) ENABLED START -----*/

//	static initializations

/*----- PROTECTED REGION END -----*/	//	BaslerCamera::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : BaslerCamera::BaslerCamera()
 *	Description : Constructors for a Tango device
 *                implementing the classBaslerCamera
 */
//--------------------------------------------------------
BaslerCamera::BaslerCamera(Tango::DeviceClass *cl, string &s)
 : TANGO_BASE_CLASS(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(BaslerCamera::constructor_1) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::constructor_1
}
//--------------------------------------------------------
BaslerCamera::BaslerCamera(Tango::DeviceClass *cl, const char *s)
 : TANGO_BASE_CLASS(cl, s)
{
	/*----- PROTECTED REGION ID(BaslerCamera::constructor_2) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::constructor_2
}
//--------------------------------------------------------
BaslerCamera::BaslerCamera(Tango::DeviceClass *cl, const char *s, const char *d)
 : TANGO_BASE_CLASS(cl, s, d)
{
	/*----- PROTECTED REGION ID(BaslerCamera::constructor_3) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : BaslerCamera::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void BaslerCamera::delete_device()
{
	DEBUG_STREAM << "BaslerCamera::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::delete_device) ENABLED START -----*/
	
	//	Delete device allocated objects
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::delete_device
	delete[] attr_ExposureTime_read;
	delete[] attr_FrameRate_read;
	delete[] attr_Gain_read;
	delete[] attr_TriggerMode_read;
	delete[] attr_BeamProfileImg_read;
}

//--------------------------------------------------------
/**
 *	Method      : BaslerCamera::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void BaslerCamera::init_device()
{
	DEBUG_STREAM << "BaslerCamera::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::init_device_before) ENABLED START -----*/
	
	//	Initialization before get_device_property() call
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::init_device_before
	
	//	No device property to be read from database
	
	attr_ExposureTime_read = new Tango::DevDouble[1];
	attr_FrameRate_read = new Tango::DevDouble[1];
	attr_Gain_read = new Tango::DevDouble[1];
	attr_TriggerMode_read = new Tango::DevUShort[1];
	attr_BeamProfileImg_read = new Tango::DevUShort[1280*1024];
	/*----- PROTECTED REGION ID(BaslerCamera::init_device) ENABLED START -----*/
	
	//	Initialize device
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::init_device
}


//--------------------------------------------------------
/**
 *	Method      : BaslerCamera::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void BaslerCamera::always_executed_hook()
{
	DEBUG_STREAM << "BaslerCamera::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::always_executed_hook) ENABLED START -----*/
	
	//	code always executed before all requests
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : BaslerCamera::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void BaslerCamera::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "BaslerCamera::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::read_attr_hardware
}
//--------------------------------------------------------
/**
 *	Method      : BaslerCamera::write_attr_hardware()
 *	Description : Hardware writing for attributes
 */
//--------------------------------------------------------
void BaslerCamera::write_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "BaslerCamera::write_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::write_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::write_attr_hardware
}

//--------------------------------------------------------
/**
 *	Read attribute ExposureTime related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void BaslerCamera::read_ExposureTime(Tango::Attribute &attr)
{
	DEBUG_STREAM << "BaslerCamera::read_ExposureTime(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::read_ExposureTime) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_ExposureTime_read);
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::read_ExposureTime
}
//--------------------------------------------------------
/**
 *	Write attribute ExposureTime related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void BaslerCamera::write_ExposureTime(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "BaslerCamera::write_ExposureTime(Tango::WAttribute &attr) entering... " << endl;
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	/*----- PROTECTED REGION ID(BaslerCamera::write_ExposureTime) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::write_ExposureTime
}
//--------------------------------------------------------
/**
 *	Read attribute FrameRate related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void BaslerCamera::read_FrameRate(Tango::Attribute &attr)
{
	DEBUG_STREAM << "BaslerCamera::read_FrameRate(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::read_FrameRate) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_FrameRate_read);
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::read_FrameRate
}
//--------------------------------------------------------
/**
 *	Write attribute FrameRate related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void BaslerCamera::write_FrameRate(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "BaslerCamera::write_FrameRate(Tango::WAttribute &attr) entering... " << endl;
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	/*----- PROTECTED REGION ID(BaslerCamera::write_FrameRate) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::write_FrameRate
}
//--------------------------------------------------------
/**
 *	Read attribute Gain related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void BaslerCamera::read_Gain(Tango::Attribute &attr)
{
	DEBUG_STREAM << "BaslerCamera::read_Gain(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::read_Gain) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_Gain_read);
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::read_Gain
}
//--------------------------------------------------------
/**
 *	Write attribute Gain related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void BaslerCamera::write_Gain(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "BaslerCamera::write_Gain(Tango::WAttribute &attr) entering... " << endl;
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	/*----- PROTECTED REGION ID(BaslerCamera::write_Gain) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::write_Gain
}
//--------------------------------------------------------
/**
 *	Read attribute TriggerMode related method
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void BaslerCamera::read_TriggerMode(Tango::Attribute &attr)
{
	DEBUG_STREAM << "BaslerCamera::read_TriggerMode(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::read_TriggerMode) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_TriggerMode_read);
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::read_TriggerMode
}
//--------------------------------------------------------
/**
 *	Write attribute TriggerMode related method
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void BaslerCamera::write_TriggerMode(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "BaslerCamera::write_TriggerMode(Tango::WAttribute &attr) entering... " << endl;
	//	Retrieve write value
	Tango::DevUShort	w_val;
	attr.get_write_value(w_val);
	/*----- PROTECTED REGION ID(BaslerCamera::write_TriggerMode) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::write_TriggerMode
}
//--------------------------------------------------------
/**
 *	Read attribute BeamProfileImg related method
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Image max = 1280 x 1024
 */
//--------------------------------------------------------
void BaslerCamera::read_BeamProfileImg(Tango::Attribute &attr)
{
	DEBUG_STREAM << "BaslerCamera::read_BeamProfileImg(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::read_BeamProfileImg) ENABLED START -----*/
	//	Set the attribute value
	attr.set_value(attr_BeamProfileImg_read, 1280, 1024);
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::read_BeamProfileImg
}

//--------------------------------------------------------
/**
 *	Method      : BaslerCamera::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void BaslerCamera::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(BaslerCamera::add_dynamic_attributes) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command GrabImage related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void BaslerCamera::grab_image()
{
	DEBUG_STREAM << "BaslerCamera::GrabImage()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(BaslerCamera::grab_image) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::grab_image
}
//--------------------------------------------------------
/**
 *	Method      : BaslerCamera::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void BaslerCamera::add_dynamic_commands()
{
	/*----- PROTECTED REGION ID(BaslerCamera::add_dynamic_commands) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic commands if any
	
	/*----- PROTECTED REGION END -----*/	//	BaslerCamera::add_dynamic_commands
}

/*----- PROTECTED REGION ID(BaslerCamera::namespace_ending) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	BaslerCamera::namespace_ending
} //	namespace