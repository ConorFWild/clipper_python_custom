#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "type_conversions.h"
#include <clipper/clipper.h>
#include <clipper/clipper-ccp4.h>

namespace py=pybind11;
using namespace clipper;

void declare_ccp4mapfile(py::module& m)
{
    py::class_<CCP4MAPfile> ccp4map(m, "CCP4MAPfile");
    ccp4mtz
        .def(py::init<>())
        .def("open_read", &CCP4MAPfile::open_read)
        // .def("open_read", [](CCP4MAPfile& self, const std::string& fname) { self.open_read(String(fname)); })
        .def("close_read", &CCP4MAPfile::close_read)
        .def("open_append", &CCP4MAPfile::open_append)
        // .def("open_append", [](CCP4MAPfile& self, const std::string& fname) { self.open_append(String(fname)); })
        .def("close_append", &CCP4MAPfile::close_append)
        .def("open_write", &CCP4MAPfile::open_write)
        // .def("open_write", [](CCP4MAPfile& self, const std::string& fname) { self.open_write(String(fname)); })
        //.def("close_write", &CCP4MAPfile::close_write)
        //.def_property_readonly("spacegroup", &CCP4MAPfile::spacegroup)
        //.def_property_readonly("cell", &CCP4MAPfile::cell)
        //.def_property_readonly("resolution", &CCP4MAPfile::resolution)
        //.def_property_readonly("hkl_sampling", &CCP4MAPfile::hkl_sampling)

        .def("import_xmap", &CCP4MAPfile::import_xmap)        
	//.def("import_hkl_info", &CCP4MAPfile::import_hkl_info)
        //.def("import_hkl_info", [](CCP4MAPfile& self, HKL_info& target) { self.import_hkl_info(target, true); })
        //.def("import_crystal", &CCP4MAPfile::import_crystal)
        //.def("import_dataset", &CCP4MAPfile::import_dataset)
        //.def("import_hkl_data", (void (CCP4MAPfile::*)(HKL_data_base&, const String)) &CCP4MAPfile::import_hkl_data)
        //.def("import_hkl_data", [](CCP4MAPfile& self, HKL_data_base& cdata, const std::string& mtzpath) { self.import_hkl_data(mtzpath); })

       

        //.def_property_readonly("column_paths", &CCP4MAPfile::column_paths)
        //.def_property_readonly("assigned_paths", &CCP4MAPfile::assigned_paths)

        //.def_property("title",
        //[] (const CCP4MAPfile& self) { return self.title().c_str(); },
        //[] (CCP4MAPfile& self, const std::string& name) { self.set_title(String(name)); }
        //)

        //.def_property("history",
        //[] (const CCP4MAPfile& self) //-> std::vector<std::string>>
        //{
        //    auto history = self.history();
        //    std::vector<std::string> hstr;
        //    for (const auto &h: history)
        //        hstr.push_back(static_cast<const std::string&>(h));
        //    return hstr;
        //},
        //[] (CCP4MAPfile& self, const std::vector<std::string>& hstr)
        //{
        //    std::vector<String> history;
        //    for (const auto& h: hstr)
        //        history.push_back(String(h));
        //    self.set_history(history);
        //})
        //.def_property_readonly("num_reflections", &CCP4MAPfile::num_reflections)
        //.def_property_readonly("sort_order", &CCP4MAPfile::sort_order)
        //.def_property_readonly("low_res_limit", &CCP4MAPfile::low_res_limit)
        //.def_property_readonly("high_res_limit", &CCP4MAPfile::high_res_limit)
        //.def_property_readonly("ccp4_spacegroup_number", &CCP4MAPfile::ccp4_spacegroup_number)
        //.def_property("spacegroup_confidence",
        //    &CCP4MAPfile::spacegroup_confidence,
        //    &CCP4MAPfile::set_spacegroup_confidence
        //)
        //.def("set_verbose", &CCP4MAPfile::set_verbose)
        ;
} // declare_CCP4MAPfile





void init_ccp4_map_io(py::module& m)
{
    declare_CCP4MAPfile(m);
} // init_ccp4_mtz_io
