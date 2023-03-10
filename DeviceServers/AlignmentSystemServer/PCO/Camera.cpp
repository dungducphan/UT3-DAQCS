/*----- PROTECTED REGION ID(Camera.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        Camera.cpp
//
// description : C++ source for the Camera class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               Camera are implemented in this file.
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


#include <Camera.h>
#include <CameraClass.h>

/*----- PROTECTED REGION END -----*/    //	Camera.cpp

/**
 *  Camera class description:
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
//  exposureTime    |  Tango::DevULong	Scalar
//  frameRate       |  Tango::DevFloat	Scalar
//  triggerMode     |  Tango::DevUShort	Scalar
//  Gain            |  Tango::DevFloat	Scalar
//  beamProfileImg  |  Tango::DevUShort	Image  ( max = 1392 x 1024)
//================================================================

namespace Camera_ns {
/*----- PROTECTED REGION ID(Camera::namespace_starting) ENABLED START -----*/

//	static initializations

/*----- PROTECTED REGION END -----*/    //	Camera::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : Camera::Camera()
 *	Description : Constructors for a Tango device
 *                implementing the classCamera
 */
//--------------------------------------------------------
    Camera::Camera(Tango::DeviceClass *cl, string &s)
            : TANGO_BASE_CLASS(cl, s.c_str()) {
        /*----- PROTECTED REGION ID(Camera::constructor_1) ENABLED START -----*/
        init_device();

        /*----- PROTECTED REGION END -----*/    //	Camera::constructor_1
    }

//--------------------------------------------------------
    Camera::Camera(Tango::DeviceClass *cl, const char *s)
            : TANGO_BASE_CLASS(cl, s) {
        /*----- PROTECTED REGION ID(Camera::constructor_2) ENABLED START -----*/
        init_device();

        /*----- PROTECTED REGION END -----*/    //	Camera::constructor_2
    }

//--------------------------------------------------------
    Camera::Camera(Tango::DeviceClass *cl, const char *s, const char *d)
            : TANGO_BASE_CLASS(cl, s, d) {
        /*----- PROTECTED REGION ID(Camera::constructor_3) ENABLED START -----*/
        init_device();

        /*----- PROTECTED REGION END -----*/    //	Camera::constructor_3
    }

//--------------------------------------------------------
/**
 *	Method      : Camera::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
    void Camera::delete_device() {
        DEBUG_STREAM << "Camera::delete_device() " << device_name << endl;
        /*----- PROTECTED REGION ID(Camera::delete_device) ENABLED START -----*/

        //	Delete device allocated objects
        delete cam;
        delete img;

        /*----- PROTECTED REGION END -----*/    //	Camera::delete_device
        delete[] attr_exposureTime_read;
        delete[] attr_frameRate_read;
        delete[] attr_triggerMode_read;
        delete[] attr_Gain_read;
        delete[] attr_beamProfileImg_read;
    }

//--------------------------------------------------------
/**
 *	Method      : Camera::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
    void Camera::init_device() {
        DEBUG_STREAM << "Camera::init_device() create device " << device_name << endl;
        /*----- PROTECTED REGION ID(Camera::init_device_before) ENABLED START -----*/

        //	Initialization before get_device_property() call

        /*----- PROTECTED REGION END -----*/    //	Camera::init_device_before

        //	No device property to be read from database

        attr_exposureTime_read = new Tango::DevULong[1];
        attr_frameRate_read = new Tango::DevFloat[1];
        attr_triggerMode_read = new Tango::DevUShort[1];
        attr_Gain_read = new Tango::DevFloat[1];
        attr_beamProfileImg_read = new Tango::DevUShort[1392 * 1024];
        /*----- PROTECTED REGION ID(Camera::init_device) ENABLED START -----*/

        //	Initialize device
        *attr_exposureTime_read = 10000000;
        *attr_triggerMode_read = 0;

        try {
            cam = new pco::Camera();
            img = new pco::Image();
            camConfig.exposure_time_s = cam->getConfiguration().exposure_time_s;
            camConfig.trigger_mode = cam->getConfiguration().trigger_mode;
        } catch (pco::CameraException &err) {
            std::cout << "Error Code: " << err.error_code() << std::endl;
            std::cout << err.what() << std::endl;
        }

        /*----- PROTECTED REGION END -----*/    //	Camera::init_device
    }


//--------------------------------------------------------
/**
 *	Method      : Camera::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
    void Camera::always_executed_hook() {
        DEBUG_STREAM << "Camera::always_executed_hook()  " << device_name << endl;
        /*----- PROTECTED REGION ID(Camera::always_executed_hook) ENABLED START -----*/

        //	code always executed before all requests

        /*----- PROTECTED REGION END -----*/    //	Camera::always_executed_hook
    }

//--------------------------------------------------------
/**
 *	Method      : Camera::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
    void Camera::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list)) {
        DEBUG_STREAM << "Camera::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
        /*----- PROTECTED REGION ID(Camera::read_attr_hardware) ENABLED START -----*/

        //	Add your own code
        std::string att_name;
        for (long i = 0; i < attr_list.size(); i++) {
            att_name = dev_attr->get_attr_by_ind(attr_list[i]).get_name();
            if (att_name == "exposureTime") {
                *attr_exposureTime_read = camConfig.exposure_time_s * 1000000000;
            } else if (att_name == "triggerMode") {
                *attr_triggerMode_read = camConfig.trigger_mode;
            }
        }
        /*----- PROTECTED REGION END -----*/    //	Camera::read_attr_hardware
    }
//--------------------------------------------------------
/**
 *	Method      : Camera::write_attr_hardware()
 *	Description : Hardware writing for attributes
 */
//--------------------------------------------------------
    void Camera::write_attr_hardware(TANGO_UNUSED(vector<long> &attr_list)) {
        DEBUG_STREAM << "Camera::write_attr_hardware(vector<long> &attr_list) entering... " << endl;
        /*----- PROTECTED REGION ID(Camera::write_attr_hardware) ENABLED START -----*/

        //	Add your own code
        try {
            cam->setConfiguration(camConfig);
        } catch (pco::CameraException &err) {
            std::cout << "Error Code: " << err.error_code() << std::endl;
            std::cout << err.what() << std::endl;
        }
        /*----- PROTECTED REGION END -----*/    //	Camera::write_attr_hardware
    }

//--------------------------------------------------------
/**
 *	Read attribute exposureTime related method
 *	Description: Exposure Time in nanoseconds.
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
    void Camera::read_exposureTime(Tango::Attribute &attr) {
        DEBUG_STREAM << "Camera::read_exposureTime(Tango::Attribute &attr) entering... " << endl;
        /*----- PROTECTED REGION ID(Camera::read_exposureTime) ENABLED START -----*/
        //	Set the attribute value
        attr.set_value(attr_exposureTime_read);
        /*----- PROTECTED REGION END -----*/    //	Camera::read_exposureTime
    }
//--------------------------------------------------------
/**
 *	Write attribute exposureTime related method
 *	Description: Exposure Time in nanoseconds.
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
    void Camera::write_exposureTime(Tango::WAttribute &attr) {
        DEBUG_STREAM << "Camera::write_exposureTime(Tango::WAttribute &attr) entering... " << endl;
        //	Retrieve write value
        Tango::DevULong w_val;
        attr.get_write_value(w_val);
        /*----- PROTECTED REGION ID(Camera::write_exposureTime) ENABLED START -----*/
        camConfig.exposure_time_s = ((double) w_val) / 1.0E9;
        /*----- PROTECTED REGION END -----*/    //	Camera::write_exposureTime
    }
//--------------------------------------------------------
/**
 *	Read attribute frameRate related method
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
    void Camera::read_frameRate(Tango::Attribute &attr) {
        DEBUG_STREAM << "Camera::read_frameRate(Tango::Attribute &attr) entering... " << endl;
        /*----- PROTECTED REGION ID(Camera::read_frameRate) ENABLED START -----*/
        //	Set the attribute value
        attr.set_value(attr_frameRate_read);

        /*----- PROTECTED REGION END -----*/    //	Camera::read_frameRate
    }
//--------------------------------------------------------
/**
 *	Write attribute frameRate related method
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
    void Camera::write_frameRate(Tango::WAttribute &attr) {
        DEBUG_STREAM << "Camera::write_frameRate(Tango::WAttribute &attr) entering... " << endl;
        //	Retrieve write value
        Tango::DevFloat w_val;
        attr.get_write_value(w_val);
        /*----- PROTECTED REGION ID(Camera::write_frameRate) ENABLED START -----*/


        /*----- PROTECTED REGION END -----*/    //	Camera::write_frameRate
    }
//--------------------------------------------------------
/**
 *	Read attribute triggerMode related method
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
    void Camera::read_triggerMode(Tango::Attribute &attr) {
        DEBUG_STREAM << "Camera::read_triggerMode(Tango::Attribute &attr) entering... " << endl;
        /*----- PROTECTED REGION ID(Camera::read_triggerMode) ENABLED START -----*/
        //	Set the attribute value
        attr.set_value(attr_triggerMode_read);

        /*----- PROTECTED REGION END -----*/    //	Camera::read_triggerMode
    }
//--------------------------------------------------------
/**
 *	Write attribute triggerMode related method
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
    void Camera::write_triggerMode(Tango::WAttribute &attr) {
        DEBUG_STREAM << "Camera::write_triggerMode(Tango::WAttribute &attr) entering... " << endl;
        //	Retrieve write value
        Tango::DevUShort w_val;
        attr.get_write_value(w_val);
        /*----- PROTECTED REGION ID(Camera::write_triggerMode) ENABLED START -----*/
        camConfig.trigger_mode = w_val;
        /*----- PROTECTED REGION END -----*/    //	Camera::write_triggerMode
    }
//--------------------------------------------------------
/**
 *	Read attribute Gain related method
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
    void Camera::read_Gain(Tango::Attribute &attr) {
        DEBUG_STREAM << "Camera::read_Gain(Tango::Attribute &attr) entering... " << endl;
        /*----- PROTECTED REGION ID(Camera::read_Gain) ENABLED START -----*/
        //	Set the attribute value
        attr.set_value(attr_Gain_read);

        /*----- PROTECTED REGION END -----*/    //	Camera::read_Gain
    }
//--------------------------------------------------------
/**
 *	Write attribute Gain related method
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
    void Camera::write_Gain(Tango::WAttribute &attr) {
        DEBUG_STREAM << "Camera::write_Gain(Tango::WAttribute &attr) entering... " << endl;
        //	Retrieve write value
        Tango::DevFloat w_val;
        attr.get_write_value(w_val);
        /*----- PROTECTED REGION ID(Camera::write_Gain) ENABLED START -----*/


        /*----- PROTECTED REGION END -----*/    //	Camera::write_Gain
    }
//--------------------------------------------------------
/**
 *	Read attribute beamProfileImg related method
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Image max = 1392 x 1024
 */
//--------------------------------------------------------
    void Camera::read_beamProfileImg(Tango::Attribute &attr) {
        DEBUG_STREAM << "Camera::read_beamProfileImg(Tango::Attribute &attr) entering... " << endl;
        /*----- PROTECTED REGION ID(Camera::read_beamProfileImg) ENABLED START -----*/
        //	Set the attribute value
        attr.set_value(attr_beamProfileImg_read, 1392, 1024);

        /*----- PROTECTED REGION END -----*/    //	Camera::read_beamProfileImg
    }

//--------------------------------------------------------
/**
 *	Method      : Camera::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
    void Camera::add_dynamic_attributes() {
        /*----- PROTECTED REGION ID(Camera::add_dynamic_attributes) ENABLED START -----*/

        //	Add your own code to create and add dynamic attributes if any

        /*----- PROTECTED REGION END -----*/    //	Camera::add_dynamic_attributes
    }

//--------------------------------------------------------
/**
 *	Command GrabImage related method
 *	Description: 
 *
 */
//--------------------------------------------------------
    void Camera::grab_image() {
        DEBUG_STREAM << "Camera::GrabImage()  - " << device_name << endl;
        /*----- PROTECTED REGION ID(Camera::grab_image) ENABLED START -----*/

        //	Add your own code
        cam->record(1, pco::RecordMode::sequence);
        cam->image(*img, 0, pco::DataFormat::Mono16);
        attr_beamProfileImg_read = &(img->vector_16bit())[0];

        /*----- PROTECTED REGION END -----*/    //	Camera::grab_image
    }
//--------------------------------------------------------
/**
 *	Method      : Camera::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
    void Camera::add_dynamic_commands() {
        /*----- PROTECTED REGION ID(Camera::add_dynamic_commands) ENABLED START -----*/

        //	Add your own code to create and add dynamic commands if any

        /*----- PROTECTED REGION END -----*/    //	Camera::add_dynamic_commands
    }

/*----- PROTECTED REGION ID(Camera::namespace_ending) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/    //	Camera::namespace_ending
} //	namespace