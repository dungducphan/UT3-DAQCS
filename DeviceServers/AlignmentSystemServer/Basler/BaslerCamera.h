/*----- PROTECTED REGION ID(BaslerCamera.h) ENABLED START -----*/
//=============================================================================
//
// file :        BaslerCamera.h
//
// description : Include file for the BaslerCamera class
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


#ifndef BaslerCamera_H
#define BaslerCamera_H

#include <tango.h>

#include <pylon/PylonIncludes.h>
#include <pylon/Device.h>

/*----- PROTECTED REGION END -----*/	//	BaslerCamera.h

/**
 *  BaslerCamera class description:
 *    
 */

namespace BaslerCamera_ns
{
/*----- PROTECTED REGION ID(BaslerCamera::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	BaslerCamera::Additional Class Declarations

class BaslerCamera : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(BaslerCamera::Data Members) ENABLED START -----*/

//	Add your own data members

        // Camera Device Object ptr
        Pylon::CInstantCamera *camera;

        // This smart pointer will receive the grab result data.
        Pylon::CGrabResultPtr ptrGrabResult;

/*----- PROTECTED REGION END -----*/	//	BaslerCamera::Data Members


//	Attribute data members
public:
	Tango::DevDouble	*attr_ExposureTime_read;
	Tango::DevDouble	*attr_FrameRate_read;
	Tango::DevDouble	*attr_Gain_read;
	Tango::DevUShort	*attr_TriggerMode_read;
	Tango::DevUShort	*attr_BeamProfileImg_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	BaslerCamera(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	BaslerCamera(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	BaslerCamera(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~BaslerCamera() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : BaslerCamera::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : BaslerCamera::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute ExposureTime related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_ExposureTime(Tango::Attribute &attr);
	virtual void write_ExposureTime(Tango::WAttribute &attr);
	virtual bool is_ExposureTime_allowed(Tango::AttReqType type);
/**
 *	Attribute FrameRate related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_FrameRate(Tango::Attribute &attr);
	virtual void write_FrameRate(Tango::WAttribute &attr);
	virtual bool is_FrameRate_allowed(Tango::AttReqType type);
/**
 *	Attribute Gain related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_Gain(Tango::Attribute &attr);
	virtual void write_Gain(Tango::WAttribute &attr);
	virtual bool is_Gain_allowed(Tango::AttReqType type);
/**
 *	Attribute TriggerMode related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Scalar
 */
	virtual void read_TriggerMode(Tango::Attribute &attr);
	virtual void write_TriggerMode(Tango::WAttribute &attr);
	virtual bool is_TriggerMode_allowed(Tango::AttReqType type);
/**
 *	Attribute BeamProfileImg related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Image max = 1280 x 1024
 */
	virtual void read_BeamProfileImg(Tango::Attribute &attr);
	virtual bool is_BeamProfileImg_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : BaslerCamera::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command GrabImage related method
	 *	Description: 
	 *
	 */
	virtual void grab_image();
	virtual bool is_GrabImage_allowed(const CORBA::Any &any);
	/**
	 *	Command ConnectCamera related method
	 *	Description: 
	 *
	 */
	virtual void connect_camera();
	virtual bool is_ConnectCamera_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : BaslerCamera::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(BaslerCamera::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes

/*----- PROTECTED REGION END -----*/	//	BaslerCamera::Additional Method prototypes
};

/*----- PROTECTED REGION ID(BaslerCamera::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	BaslerCamera::Additional Classes Definitions

}	//	End of namespace

#endif   //	BaslerCamera_H
