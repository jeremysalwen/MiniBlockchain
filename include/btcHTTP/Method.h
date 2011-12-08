
#ifndef METHOD_H
#define METHOD_H

#include <string>
#include <map>
#include <boost/noncopyable.hpp>
#include "json/json_spirit.h"

/// The base class for Method functors - The definitions follow the JSON_RPC 2.0 definition and strives at introspection support.
class Method
{
public:
    /// The actual function call - you need to overload this to implement a method
    virtual json_spirit::Value operator()(const json_spirit::Array& params, bool fHelp) = 0;
    
    /// Get the name of the method. Default implemented by lowercase typeid name. - REQUIRED
    virtual const std::string name() const; 
    
    virtual const std::string summary() const { return ""; } // OPTIONAL
    virtual const std::string help() const { return ""; } // OPTIONAL
    virtual const std::string params() const  { return ""; } // OPTIONAL
    virtual const std::string ret() const { return ""; } // OPTIONAL
};

typedef boost::shared_ptr<Method> method_ptr;
typedef std::map<std::string, method_ptr> Methods;

#endif // METHOD_H
