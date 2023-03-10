/*----- PROTECTED REGION ID(DeviceBClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        DeviceBClass.h
//
// description : Include for the DeviceB root class.
//               This class is the singleton class for
//                the DeviceB device class.
//               It contains all properties and methods which the 
//               DeviceB requires only once e.g. the commands.
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


#ifndef DeviceBClass_H
#define DeviceBClass_H

#include <tango.h>
#include <DeviceB.h>


/*----- PROTECTED REGION END -----*/	//	DeviceBClass.h


namespace DeviceB_ns
{
/*----- PROTECTED REGION ID(DeviceBClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	DeviceBClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute Temperature_B1 class definition
class Temperature_B1Attrib: public Tango::Attr
{
public:
	Temperature_B1Attrib():Attr("Temperature_B1",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~Temperature_B1Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<DeviceB *>(dev))->read_Temperature_B1(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<DeviceB *>(dev))->is_Temperature_B1_allowed(ty);}
};

//	Attribute Temperature_B2 class definition
class Temperature_B2Attrib: public Tango::Attr
{
public:
	Temperature_B2Attrib():Attr("Temperature_B2",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~Temperature_B2Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<DeviceB *>(dev))->read_Temperature_B2(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<DeviceB *>(dev))->is_Temperature_B2_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command MeasureTemp class definition
class MeasureTempClass : public Tango::Command
{
public:
	MeasureTempClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	MeasureTempClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~MeasureTempClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<DeviceB *>(dev))->is_MeasureTemp_allowed(any);}
};


/**
 *	The DeviceBClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  DeviceBClass : public Tango::DeviceClass
#else
class DeviceBClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(DeviceBClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	DeviceBClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static DeviceBClass *init(const char *);
		static DeviceBClass *instance();
		~DeviceBClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		DeviceBClass(string &);
		static DeviceBClass *_instance;
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

#endif   //	DeviceB_H
