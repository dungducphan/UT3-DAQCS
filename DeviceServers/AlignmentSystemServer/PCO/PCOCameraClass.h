/*----- PROTECTED REGION ID(PCOCameraClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        PCOCameraClass.h
//
// description : Include for the PCOCamera root class.
//               This class is the singleton class for
//                the PCOCamera device class.
//               It contains all properties and methods which the 
//               PCOCamera requires only once e.g. the commands.
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


#ifndef PCOCameraClass_H
#define PCOCameraClass_H

#include <tango.h>
#include <PCOCamera.h>


/*----- PROTECTED REGION END -----*/	//	PCOCameraClass.h


namespace PCOCamera_ns
{
/*----- PROTECTED REGION ID(PCOCameraClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	PCOCameraClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute exposureTime class definition
class exposureTimeAttrib: public Tango::Attr
{
public:
	exposureTimeAttrib():Attr("exposureTime",
			Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~exposureTimeAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<PCOCamera *>(dev))->read_exposureTime(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<PCOCamera *>(dev))->write_exposureTime(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<PCOCamera *>(dev))->is_exposureTime_allowed(ty);}
};

//	Attribute frameRate class definition
class frameRateAttrib: public Tango::Attr
{
public:
	frameRateAttrib():Attr("frameRate",
			Tango::DEV_FLOAT, Tango::READ_WRITE) {};
	~frameRateAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<PCOCamera *>(dev))->read_frameRate(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<PCOCamera *>(dev))->write_frameRate(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<PCOCamera *>(dev))->is_frameRate_allowed(ty);}
};

//	Attribute triggerMode class definition
class triggerModeAttrib: public Tango::Attr
{
public:
	triggerModeAttrib():Attr("triggerMode",
			Tango::DEV_USHORT, Tango::READ_WRITE) {};
	~triggerModeAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<PCOCamera *>(dev))->read_triggerMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<PCOCamera *>(dev))->write_triggerMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<PCOCamera *>(dev))->is_triggerMode_allowed(ty);}
};

//	Attribute Gain class definition
class GainAttrib: public Tango::Attr
{
public:
	GainAttrib():Attr("Gain",
			Tango::DEV_FLOAT, Tango::READ_WRITE) {};
	~GainAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<PCOCamera *>(dev))->read_Gain(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<PCOCamera *>(dev))->write_Gain(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<PCOCamera *>(dev))->is_Gain_allowed(ty);}
};

//	Attribute beamProfileImg class definition
class beamProfileImgAttrib: public Tango::ImageAttr
{
public:
	beamProfileImgAttrib():ImageAttr("beamProfileImg",
			Tango::DEV_USHORT, Tango::READ, 1392, 1024) {};
	~beamProfileImgAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<PCOCamera *>(dev))->read_beamProfileImg(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<PCOCamera *>(dev))->is_beamProfileImg_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command GrabImage class definition
class GrabImageClass : public Tango::Command
{
public:
	GrabImageClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GrabImageClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GrabImageClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<PCOCamera *>(dev))->is_GrabImage_allowed(any);}
};


/**
 *	The PCOCameraClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  PCOCameraClass : public Tango::DeviceClass
#else
class PCOCameraClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(PCOCameraClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	PCOCameraClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static PCOCameraClass *init(const char *);
		static PCOCameraClass *instance();
		~PCOCameraClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		PCOCameraClass(string &);
		static PCOCameraClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	PCOCamera_H
