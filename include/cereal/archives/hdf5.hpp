#pragma once


#include <iostream>
#include <sstream>
#include <type_traits>
#include <memory>
#include <vector>
#include <string>

#include "cereal/cereal.hpp"
#include "cereal/details/util.hpp"

//#include "hdf5_types.hpp"

//#include "H5Cpp.h"

//#include "hdf5.h"




namespace cereal {

//  ######################################################
//  An output archive designed to save data in HDF5 format
//  ######################################################


//using namespace H5;

  class HDF5OutputArchive : public OutputArchive<HDF5OutputArchive>
{
public:
    //HDF5OutputArchive(const std::string& h5_file_name,
    //                  const std::string& hash_value,
    //                  const std::string& module_name = "Cache Result Map")
    //HDF5OutputArchive(const std::string& h5_file_name)
    HDF5OutputArchive(const char* h5_file_name = nullptr)
            :
            OutputArchive<HDF5OutputArchive>(this)
            // _hash_value(hash_value)
    //,_h5_file(h5_file_name, H5F_ACC_RDWR)
    {
    std::cout <<
              "construc: " << h5_file_name
              << std::endl;
       

        // Disable error messages so we can handle exceptions correctly
//        H5::Exception::dontPrint();

//// Open existing file
//        try
//        {
///* DEBUG
//   Use TRUNC for now so new files are created every time...*/
////vama            _h5_file = H5File(h5_file_name, H5F_ACC_RDWR);
//        }
//// File doesn't exist yet
//        catch(H5::FileIException&)
//        {
////vama            _h5_file = H5File(h5_file_name, H5F_ACC_TRUNC);
//        }
//
//        try
//        {
////vama            _h5_group = _h5_file.openGroup(hash_value);
//        }
//        catch(FileIException&) //Root module group doesn't already exist
//        {
////vama            _h5_group = _h5_file.createGroup(hash_value);
//        }

    }
    void open(const char* filename) {
            std::cout << "h5 this open " << filename << std::endl;
 //           file_id = H5Fcreate(filename, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);
    }


    //Destructor closes the file handle. Close with MPI is a collective call.
    ~HDF5OutputArchive()
    {
//        _h5_group.close();
//        _h5_file.close();
    }


      void addAttributes( const std::vector<std::string>& attrs)
      {
//Extra
/*
      bool writeAttr=0;
      if(writeAttr==1)
      {
      hsize_t dims[1]{1};
      std::string attr_data1("Attribute 1");
      StrType strdatatype(PredType::C_S1, 256);
      DataSpace attr_dataspace = DataSpace(1, dims);
      Attribute attribute = dataset.createAttribute("Test attributes",
                                                    strdatatype,
                                                    attr_dataspace);
      attribute.write(strdatatype, attr_data1.c_str());
      }
      */
//          StrType strdatatype(PredType::C_S1, H5T_VARIABLE);
//          const int RANK = 1;
//          hsize_t dims[RANK];
//          dims[0] = attrs.size();
//
//          DataSpace attrs_dataspace(RANK, dims);
//
//          Attribute attribute = _h5_group.createAttribute("Group "
//                                                                  "Description",
//                                                          strdatatype,
//                                                          attrs_dataspace);
//
//
//
//          std::vector<const char*> c_attrs;
//
//          for(int i=0; i<attrs.size(); ++i)
//              c_attrs.push_back(attrs[i].c_str());
//
//          //for(auto i : attrs)
////              c_attrs.push_back(i.c_str());
//
//
//          attribute.write(strdatatype, (void*)&c_attrs[0]);
//
//
///*
//          Attribute add
//          hsize_t dims[1]{2};
//          std::string attr_data1("Attribute 1");
//          std::string attr_data2("Attribute 2");
//
//          DataSpace attr_dataspace = DataSpace(1, dims);
//
//          attribute.write(strdatatype, attr_data1.c_str());
//
////          attribute.write(strdatatype, attr_data2.c_str());
//*/
      }



      //TODO: move these to their own struct, and perhaps make private
      std::string _hash_value;
      size_t _container_size = 1;
//      DataType _h5_type;
//      DataSpace _h5_dataspace;
//      DataSet _h5_dataset;
//      H5File _h5_file;
//      Group _h5_group;
//      size_t _index=0;
//      size_t _dataset_counter=0;


private:

  };


//class HDF5InputArchive : public InputArchive<HDF5InputArchive> {};
//
//
template <class T>
using scalar_t = std::enable_if_t<std::is_scalar<T>::value>;
//
template <class T>
using non_scalar_t = std::enable_if_t<std::negation_v<std::is_scalar<T>> >;
//
//
//
//
//  // ######################################################################
//  //! Prologue for NVPs for HDF5 output archives
//
//TODO: ALl NVPs are recognized as non-scalar!
 template <class T> inline
  static scalar_t<T> prologue(
  	HDF5OutputArchive& ar, NameValuePair<T> const & data )
  {
      std::cout <<
                "Prologue: NVP Scalar OA"
                << std::endl;
  }

template <class T> inline
static non_scalar_t<T> prologue(
        HDF5OutputArchive& ar, NameValuePair<T> const & data )
{
    std::cout <<
              "Prologue: NVP Non-scalar OA"
              << std::endl;
}
//
//  //! Prologue for NVPs for HDF5 input archives
//  template <class T> inline
//  void prologue( HDF5InputArchive &, NameValuePair<T> const & )
//  {
//      std::cout <<
//                "Prologue: NVP IA"
//                << std::endl;
//
//  }
//
  // ######################################################################
  //! Epilogue for NVPs for HDF5 output archives
 template <class T> inline
 void epilogue( HDF5OutputArchive &, NameValuePair<T> const & )
  {
      std::cout <<
                "Epilogue: NVP OA"
                << std::endl;

  }

//  //! Epilogue for NVPs for HDF5 input archives
//  template <class T> inline
//  void epilogue( HDF5InputArchive &, NameValuePair<T> const & )
//  {
//      std::cout <<
//                "Epilogue: NVP IA"
//                << std::endl;
//
//  }
//
  // ######################################################################
  //! Prologue for SizeTags for HDF5 output archives
  template <class T> inline
  void prologue( HDF5OutputArchive & ar, SizeTag<T> const & sz )
  {
      std::cout << "Prologue: SizeTag OA" << std::endl;
//      size_t size = sz.size;
//      ar._container_size = size;
////      std::cout << "Container size is: " << ar._container_size << std::endl;
//
//
//        int rank = 1;
//        hsize_t dims[rank];
//        dims[0] = size;
//        ar._h5_dataspace = DataSpace(rank, dims);
////      ar._h5_group.createDataSet(ar._hash_value, ar._h5_type, ar
////              ._h5_dataspace);
//
////      Group mGroup = ar._h5_file.openGroup("/Default_Module_Name/hash_val1");
////      mGroup.createDataSet(ar._hash_value, ar._h5_type, ar._h5_dataspace);
//
//      ar._h5_group.createDataSet(ar._hash_value, ar._h5_type, ar._h5_dataspace);
//
//
//
  }
//
//  template <class T> inline
//  void prologue( HDF5InputArchive &, SizeTag<T> const & )
//  {
//      std::cout <<
//                "Prologue: SizeTag IA"
//                << std::endl;
//
//  }
//
  //! Epilogue for SizeTags for HDF5 output archives
  template <class T> inline
  void epilogue( HDF5OutputArchive &, SizeTag<T> const & )
  {
//      std::cout <<
//                "Epilogue: SizeTag OA"
//                << std::endl;

  }
//
//  template <class T> inline
//  void epilogue( HDF5InputArchive &, SizeTag<T> const & )
//  {
//      std::cout <<
//                "Epilogue: SizeTag IA"
//                << std::endl;
//
//  }
//
//
//
//
  // ######################################################################
  //! Prologue for all other types for HDF5 output archives (except minimal types)
template <class T>
static scalar_t<T> prologue(
        HDF5OutputArchive& ar, T const & data)
{
////    std::cout << "Prologue: Default Scalar OA" << std::endl;
//
//    ar._h5_type =  CtoHDF5<T>::h5Type;
//
//    if(ar._container_size==1) //True scalar, not a scalar element of container
//    {
//        int rank = 1;
//        hsize_t dims[rank];
//        dims[0] = 1;
//        ar._h5_dataspace = DataSpace(rank, dims);
//
//        ar._h5_group.createDataSet(ar._hash_value, ar._h5_type, ar
//                ._h5_dataspace);
//
//
//    }
//
//
//
//
//
}
//
//
//
//
//
//
template <class T>
static non_scalar_t<T> prologue(
        HDF5OutputArchive& ar, T const & data)
{
    std::cout << "Prologue: Default Non-Scalar OA" << std::endl;
//
//    ar._h5_type = CtoHDF5<typename T::value_type>::h5Type;
//
//
//
//
}
//
//
//
//
//
//
//
//  //! Prologue for all other types for HDF5 input archives (except minimal types)
//  template <class T, traits::DisableIf<traits::has_minimal_base_class_serialization<T, traits::has_minimal_input_serialization, HDF5InputArchive>::value ||
//                                       traits::has_minimal_input_serialization<T, HDF5InputArchive>::value> = traits::sfinae> inline
//  void prologue( HDF5InputArchive & ar, T const & )
//  {
//      std::cout <<
//                "Prologue: Default IA"
//                << std::endl;
//  }
//
  // ######################################################################
  //! Epilogue for all other types other for HDF5 output archives (except minimal types)
  template <class T, traits::DisableIf<traits::has_minimal_base_class_serialization<T, traits::has_minimal_output_serialization, HDF5OutputArchive>::value ||
                                       traits::has_minimal_output_serialization<T, HDF5OutputArchive>::value> = traits::sfinae> inline
  void epilogue( HDF5OutputArchive & ar, T const & )
  {
      std::cout <<
               "Epilogue: Default OA"
                << std::endl;
  }

//  //! Epilogue for all other types other for HDF5 output archives (except minimal types)
//  template <class T, traits::DisableIf<traits::has_minimal_base_class_serialization<T, traits::has_minimal_input_serialization, HDF5InputArchive>::value ||
//                                       traits::has_minimal_input_serialization<T, HDF5InputArchive>::value> = traits::sfinae> inline
//  void epilogue( HDF5InputArchive & ar, T const & )
//  {
//      std::cout <<
//                "Epilogue: Default IA"
//                << std::endl;
//  }
//
  // ######################################################################
  // Common HDF5Archive serialization functions
  // ######################################################################

  //! Saving NVP types to HDF5
  template <class T> inline
  void CEREAL_SAVE_FUNCTION_NAME( HDF5OutputArchive & ar, NameValuePair<T> const & t )
  {
      std::cout <<
                "Save: NVP"
                << std::endl;
  }
//
//  //! Loading NVP types from HDF5
//  template <class T> inline
//  void CEREAL_LOAD_FUNCTION_NAME( HDF5InputArchive & ar, NameValuePair<T> & t )
//  {
//      std::cout <<
//                "Load: NVP"
//                << std::endl;
//  }
//
  // ######################################################################
  //! Saving SizeTags to HDF5
  template <class T> inline
  void CEREAL_SAVE_FUNCTION_NAME( HDF5OutputArchive &, SizeTag<T> const & )
  {
      std::cout <<
                "Save: SizeTag"
                << std::endl;
  }
//
//  //! Loading SizeTags from HDF5
//  template <class T> inline
//  void CEREAL_LOAD_FUNCTION_NAME( HDF5InputArchive & ar, SizeTag<T> & st )
//  {
//      std::cout <<
//                "Load: SizeTag"
//                << std::endl;
//  }
//
  // ######################################################################
  //! Saving for POD types to hdf5
  template <class T, traits::EnableIf<std::is_arithmetic<T>::value> = traits::sfinae> inline
  void CEREAL_SAVE_FUNCTION_NAME(HDF5OutputArchive & ar, T & data)
  {

      std::cout << "Save: POD/Arithmetic" << std::endl;
//      std::cout << "t value" << data.value <<std::endl;
      T* myData = &data;
      //std::cout << "data value" << ar._index <<std::endl;
//
//      //TODO: change this to open the group. Dataset should not have the same
//      // name as the hash_value. Name datasets by index 0, 1, etc.
//      DataSet dataset = ar._h5_group.openDataSet(ar._hash_value);
//
//      hsize_t offset[1]{ar._index};
//      hsize_t count[1]{1};
//      hsize_t stride[1]{1};
//      hsize_t block[1]{1};
//      hsize_t dims_offset[1]{1};
//
//
//      DataSpace memspace(1, dims_offset, NULL);
//
//      ar._h5_dataspace = dataset.getSpace();
//
//      ar._h5_dataspace.selectHyperslab(H5S_SELECT_SET, count, offset, stride, block);
//
//      dataset.write(myData, ar._h5_type, memspace, ar._h5_dataspace);
//          ar._index++;
//
//
  }
//
//  //! Loading for POD types from hdf5
//  template <class T, traits::EnableIf<std::is_arithmetic<T>::value> = traits::sfinae> inline
//  void CEREAL_LOAD_FUNCTION_NAME(HDF5InputArchive & ar, T & t)
//  {
//      std::cout <<
//                "Load: POD/Arithmetic"
//                << std::endl;
//  }
//
//  // ######################################################################
//  //! saving string to hdf5
////TODO
  template<class CharT, class Traits, class Alloc> inline
  void CEREAL_SAVE_FUNCTION_NAME(HDF5OutputArchive & ar, std::basic_string<CharT, Traits, Alloc> const & str)
  {
      std::cout << "Save: String" << std::endl;



  }

//  //! loading string from hdf5
//  template<class CharT, class Traits, class Alloc> inline
//  void CEREAL_LOAD_FUNCTION_NAME(HDF5InputArchive & ar, std::basic_string<CharT, Traits, Alloc> & str)
//  {
//      std::cout <<
//                "Load: String"
//                << std::endl;
//  }
//



} // End namespace cereal
//
//// register archives for polymorphic support
//CEREAL_REGISTER_ARCHIVE(cereal::HDF5InputArchive)
CEREAL_REGISTER_ARCHIVE(cereal::HDF5OutputArchive)
//
//// tie input and output archives together
//CEREAL_SETUP_ARCHIVE_TRAITS(cereal::HDF5InputArchive, cereal::HDF5OutputArchive)






