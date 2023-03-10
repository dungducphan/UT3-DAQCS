/*----- PROTECTED REGION ID(DeviceAClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        DeviceAClass.h
//
// description : Include for the DeviceA root class.
//               This class is the singleton class for
//                the DeviceA device class.
//               It contains all properties and methods which the 
//               DeviceA requires only once e.g. the commands.
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


#ifndef DeviceAClass_H
#define DeviceAClass_H

#include <tango.h>
#include <DeviceA.h>


/*----- PROTECTED REGION END -----*/	//	DeviceAClass.h


namespace DeviceA_ns
{
/*----- PROTECTED REGION ID(DeviceAClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	DeviceAClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute TestAttribute_A1 class definition
class TestAttribute_A1Attrib: public Tango::Attr
{
public:
	TestAttribute_A1Attrib():Attr("TestAttribute_A1",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~TestAttribute_A1Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<DeviceA *>(dev))->read_TestAttribute_A1(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<DeviceA *>(dev))->write_TestAttribute_A1(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<DeviceA *>(dev))->is_TestAttribute_A1_allowed(ty);}
};

//	Attribute TestAttribute_A2 class definition
class TestAttribute_A2Attrib: public Tango::Attr
{
public:
	TestAttribute_A2Attrib():Attr("TestAttribute_A2",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~TestAttribute_A2Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<DeviceA *>(dev))->read_TestAttribute_A2(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<DeviceA *>(dev))->write_TestAttribute_A2(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<DeviceA *>(dev))->is_TestAttribute_A2_allowed(ty);}
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
	{return (static_cast<DeviceA *>(dev))->is_GrabImage_allowed(any);}
};


/**
 *	The DeviceAClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  DeviceAClass : public Tango::DeviceClass
#else
class DeviceAClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(DeviceAClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static DeviceAClass *init(const char *);
		static DeviceAClass *instance();
		~DeviceAClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		DeviceAClass(string &);
		static DeviceAClass *_instance;
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

#endif   //	DeviceA_H