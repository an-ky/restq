/*
 * Copyright 2014-2016, Corvusoft Ltd, All Rights Reserved.
 */

#ifndef _RESTQ_DETAIL_RULE_ETAG_H
#define _RESTQ_DETAIL_RULE_ETAG_H 1

//System Includes
#include <map>
#include <string>
#include <memory>
#include <functional>

//Project Includes
#include <corvusoft/restq/byte.hpp>
#include <corvusoft/restq/string.hpp>
#include <corvusoft/restq/session.hpp>
#include <corvusoft/restq/request.hpp>
#include <corvusoft/restq/resource.hpp>
#include <corvusoft/restq/detail/rule/date.hpp>

//External Includes
#include <corvusoft/restbed/rule.hpp>

//System Namespaces
using std::hash;
using std::string;
using std::function;
using std::to_string;
using std::shared_ptr;

//Project Namespaces

//External Namespaces
using restbed::Rule;

namespace restq
{
    namespace detail
    {
        class ETag final : public Rule
        {
            public:
                ETag( void ) : Rule( )
                {
                    return;
                }
                
                virtual ~ETag( void )
                {
                    return;
                }
                
                bool condition( const shared_ptr< Session > ) final override
                {
                    return false;
                }
                
                void action( const shared_ptr< Session > session, const function< void ( const shared_ptr< Session > ) >& callback ) final override
                {
                    callback( session );
                }
                
                static Bytes make( void )
                {
                    static hash< string > hasher;
                    static const size_t minimum_length = 20;
                    
                    auto etag = ::to_string( hasher( Date::make( ) ) );
                    etag.append( minimum_length - etag.length( ), '0' );
                    
                    return String::to_bytes( String::format( "%s", etag.data( ) ) );
                }
                
                static string make( const Resources& values )
                {
                    auto etag = string{ "00000000000000000000" };
                    
                    if ( not values.empty( ) and values.back( ).count( "revision" ) )
                    {
                        etag = String::to_string( values.back( ).lower_bound( "revision" )->second );
                    }
                    
                    return "\"" + etag + "\"";
                }
        };
    }
}

#endif  /* _RESTQ_DETAIL_RULE_ETAG_H */
