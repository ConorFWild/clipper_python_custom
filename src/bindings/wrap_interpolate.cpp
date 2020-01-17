#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/numpy.h>

#include "type_conversions.h"
#include <clipper/clipper.h>
#include "numpy_helper.h"

namespace py=pybind11;
using namespace clipper;

// A function to interpolate onto a numpy array

void interpolate(clipper::NXmap<float>& nxmap, clipper::Xmap<float>& xmap) {

	typedef clipper::NXmap<float>::Map_reference_index NRI;
	typedef clipper::Interp_linear INTERP;

	for ( NRI inx = nxmap.first(); !inx.last(); inx.next() ) {
                const clipper::Coord_orth co = inx.coord_orth();
                nxmap[inx] = xmap.interp<INTERP>( xmap.coord_map( co ) );
        }


}

void init_interpolate(py::module &m) {
	m.def("interpolate", &interpolate, "A function for interpolating onto a nxmap")
	.def("rotate_translate", [](clipper::Xmap<float>& base, clipper::Xmap<float>& target, RTop_orth& rtop){
		typedef clipper::Xmap<float>::Map_reference_index NRI;
		typedef clipper::Interp_linear INTERP;

		for ( NRI inx = base.first(); !inx.last(); inx.next() ) {
					clipper::Coord_orth co = inx.coord_orth();
					clipper::Coord_orth co_transformed = rtop * co;
					target[inx] = base.interp<INTERP>( base.coord_map( co_transformed ) );
			}
	;});

}






/*
void interpolate(char* mtz_path, float* origin, float* rotation, float* grid_dimensions, float grid_step) {

	// Define crystalography objects
        clipper::HKL_info myhkl;            // define objects
        clipper::HKL_data<clipper::data32::F_phi> fphidata( myhkl );

	// Read in the data
        clipper::CCP4MTZfile mtzin;
        mtzin.open_read( mtz_path );        // open new file
        mtzin.import_hkl_info( myhkl );     // read sg, cell, reso, hkls
        mtzin.import_hkl_data( fphidata, myset, myxtl, [FWT,PHWT]" );
        mtzin.close_read();

	// Define an xmap
        clipper::Xmap xmap;

	// FFT onto it
        xmap.fft_from(fphidata);

	// Define the rotation matrix (including scaling)
        clipper::Vec3 trans(origin[0], origin[1], origin[2]);
        clipper::RTop rtop;
        clipper::Rotation rot(rotation[0], rotation[1], rotation[2])
	clipper::Mat33 scale(grid_step, 0, 0, 
			     0, grid_step, 0,
			     0, 0, grid_step);
        rtop.trn(trans);
        rtop.rot(rot.matrix()*scale);

	// Define the grid
        int nu = grid_dimensions[0];
        int nv = grid_dimensions[1];
        int nw = grid_dimensions[2];
        clipper::Grid(nu, nv, nw);

	// Define the nxmap from grid and rotation object
        clipper::NXmap nxmap(grid, rtop);

	// Define the interpolator and map iterator
        typedef clipper::NXmap<float>::Map_reference_index NRI;
        typedef clipper::Interp_linear INTERP;

	// Interpolate onto the NXmap grid

        for ( NRI inx = nxmap.first(); !inx.last(); inx.next() ) {
                const clipper::Coord_orth co = inx.coord_orth();
                nxmap[inx] = xmap.interp<INTERP>( xmap.coord_map( co ) );
        }

	// Return a pointer to the nxmap

        return nxmap
}
*/
