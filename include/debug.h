#ifndef MATRICKS_DEBUG_H
#define MATRICKS_DEBUG_H


namespace matricks {
  namespace debug {

    template <typename D>
      void _matricksinfo(const Vector<D>& a, std::string varname)
      {
	std::ostringstream stream;
	stream <<"SUMMARY for '" << varname << "':  "<< a.fullclassname()  << "[size=" << a.size() <<"]"<<", VectorID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
	std::cout <<  stream.str() <<std::endl;
      }

    template <typename D>
      void _matricksinfo(const p3vector<D>& a, std::string varname)
      {
	std::ostringstream stream;
	stream <<"SUMMARY for '" << varname << "': "<< a.fullclassname()  << "[size=" << a.size() <<"]";
	std::cout <<  stream.str() <<std::endl;
      }
    template <typename D>
      void _matricksinfo(const Matrix<D>& a, std::string varname)
      {
	std::ostringstream stream;
	stream <<"SUMMARY for '" << varname << "':  "<< a.fullclassname()  << "[size=" << a.Nrows() << "x" << a.Ncols()<<"]"<<", MatrixID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
	std::cout <<  stream.str() <<std::endl;
      }

  
  };
};



#endif
