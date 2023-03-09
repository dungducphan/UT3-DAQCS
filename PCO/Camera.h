/*----- PROTECTED REGION ID(Camera.h) ENABLED START -----*/
//=============================================================================
//
// file :        Camera.h
//
// description : Include file for the Camera class
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


#ifndef Camera_H
#define Camera_H

#include <tango.h>

#include <pco_linux_defs.h>
#include <stdafx.h>
#include <camera.h>
#include <cameraexception.h>

/*----- PROTECTED REGION END -----*/    //	Camera.h

/**
 *  Camera class description:
 *    
 */

namespace Camera_ns {
/*----- PROTECTED REGION ID(Camera::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/    //	Camera::Additional Class Declarations

    class Camera : public TANGO_BASE_CLASS {

/*----- PROTECTED REGION ID(Camera::Data Members) ENABLED START -----*/

//	Add your own data members
        pco::Camera *cam;
        pco::Image *img;
        pco::Configuration camConfig;

/*----- PROTECTED REGION END -----*/    //	Camera::Data Members


//	Attribute data members
    public:
        Tango::DevULong *attr_exposureTime_read;
        Tango::DevFloat *attr_frameRate_read;
        Tango::DevUShort *attr_triggerMode_read;
        Tango::DevFloat *attr_Gain_read;
        Tango::DevUShort *attr_beamProfileImg_read;

//	Constructors and destructors
    public:
        /**
         * Constructs a newly device object.
         *
         *	@param cl	Class.
         *	@param s 	Device Name
         */
        Camera(Tango::DeviceClass *cl, string &s);

        /**
         * Constructs a newly device object.
         *
         *	@param cl	Class.
         *	@param s 	Device Name
         */
        Camera(Tango::DeviceClass *cl, const char *s);

        /**
         * Constructs a newly device object.
         *
         *	@param cl	Class.
         *	@param s 	Device name
         *	@param d	Device description.
         */
        Camera(Tango::DeviceClass *cl, const char *s, const char *d);

        /**
         * The device object destructor.
         */
        ~Camera() { delete_device(); };


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
         *	Method      : Camera::read_attr_hardware()
         *	Description : Hardware acquisition for attributes.
         */
        //--------------------------------------------------------
        virtual void read_attr_hardware(vector<long> &attr_list);
        //--------------------------------------------------------
        /*
         *	Method      : Camera::write_attr_hardware()
         *	Description : Hardware writing for attributes.
         */
        //--------------------------------------------------------
        virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute exposureTime related methods
 *	Description: Exposure Time in nanoseconds.
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Scalar
 */
        virtual void read_exposureTime(Tango::Attribute &attr);

        virtual void write_exposureTime(Tango::WAttribute &attr);

        virtual bool is_exposureTime_allowed(Tango::AttReqType type);

/**
 *	Attribute frameRate related methods
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
        virtual void read_frameRate(Tango::Attribute &attr);

        virtual void write_frameRate(Tango::WAttribute &attr);

        virtual bool is_frameRate_allowed(Tango::AttReqType type);

/**
 *	Attribute triggerMode related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Scalar
 */
        virtual void read_triggerMode(Tango::Attribute &attr);

        virtual void write_triggerMode(Tango::WAttribute &attr);

        virtual bool is_triggerMode_allowed(Tango::AttReqType type);

/**
 *	Attribute Gain related methods
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
        virtual void read_Gain(Tango::Attribute &attr);

        virtual void write_Gain(Tango::WAttribute &attr);

        virtual bool is_Gain_allowed(Tango::AttReqType type);

/**
 *	Attribute beamProfileImg related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Image max = 1392 x 1024
 */
        virtual void read_beamProfileImg(Tango::Attribute &attr);

        virtual bool is_beamProfileImg_allowed(Tango::AttReqType type);


        //--------------------------------------------------------
        /**
         *	Method      : Camera::add_dynamic_attributes()
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


        //--------------------------------------------------------
        /**
         *	Method      : Camera::add_dynamic_commands()
         *	Description : Add dynamic commands if any.
         */
        //--------------------------------------------------------
        void add_dynamic_commands();

/*----- PROTECTED REGION ID(Camera::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes

/*----- PROTECTED REGION END -----*/    //	Camera::Additional Method prototypes
    };

/*----- PROTECTED REGION ID(Camera::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/    //	Camera::Additional Classes Definitions

}    //	End of namespace

#endif   //	Camera_H
