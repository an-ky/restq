/*
 * Copyright 2014-2016, Corvusoft Ltd, All Rights Reserved.
 */

//System Includes
#include <utility>

//Project Includes
#include "corvusoft/restq/query.hpp"
#include "corvusoft/restq/string.hpp"
#include "corvusoft/restq/session.hpp"
#include "corvusoft/restq/detail/query_impl.hpp"

//External Includes

//System Namespaces
using std::set;
using std::pair;
using std::size_t;
using std::string;
using std::vector;
using std::multimap;
using std::make_pair;
using std::shared_ptr;
using std::numeric_limits;

//Project Namespaces
using restq::detail::QueryImpl;

//External Namespaces

namespace restq
{
    Query::Query( void ) : m_pimpl( new QueryImpl )
    {
        return;
    }
    
    Query::Query( const shared_ptr< Session >& value ) : m_pimpl( new QueryImpl )
    {
        if ( value == nullptr )
        {
            return;
        }
        
        if ( value->has( "paging" ) )
        {
            const pair< size_t, size_t > paging = value->get( "paging" );
            m_pimpl->m_index = paging.first;
            m_pimpl->m_limit = paging.second;
        }
        
        if ( value->has( "keys" ) )
        {
            vector< string > temp = value->get( "keys" );
            m_pimpl->m_keys = temp;
        }
        
        if ( value->has( "include" ) )
        {
            Bytes temp = value->get( "include" );
            m_pimpl->m_include = temp;
        }
        
        if ( value->has( "inclusive_filters" ) )
        {
            multimap< string, Bytes > temp = value->get( "inclusive_filters" );
            m_pimpl->m_inclusive_filters = temp;
        }
        
        if ( value->has( "exclusive_filters" ) )
        {
            multimap< string, Bytes > temp = value->get( "exclusive_filters" );
            m_pimpl->m_exclusive_filters = temp;
        }
        
        if ( value->has( "fields" ) )
        {
            set< string > temp = value->get( "fields" );
            m_pimpl->m_fields = temp;
        }
        
        m_pimpl->m_session = value;
    }
    
    Query::~Query( void )
    {
        delete m_pimpl;
    }
    
    void Query::clear( void )
    {
        m_pimpl->m_keys.clear( );
        m_pimpl->m_error_code = 0;
        m_pimpl->m_fields.clear( );
        m_pimpl->m_include.clear( );
        m_pimpl->m_session = nullptr;
        m_pimpl->m_resultset.clear( );
        m_pimpl->m_inclusive_filters.clear( );
        m_pimpl->m_exclusive_filters.clear( );
        m_pimpl->m_index = numeric_limits< size_t >::min( );
        m_pimpl->m_limit = numeric_limits< size_t >::max( );
    }
    
    bool Query::has_failed( void ) const
    {
        return m_pimpl->m_error_code not_eq 0;
    }
    
    bool Query::has_fields( void ) const
    {
        return not m_pimpl->m_fields.empty( );
    }
    
    bool Query::has_resultset( void ) const
    {
        return not m_pimpl->m_resultset.empty( );
    }
    
    Bytes Query::get_include( void ) const
    {
        return m_pimpl->m_include;
    }
    
    int Query::get_error_code( void ) const
    {
        return m_pimpl->m_error_code;
    }
    
    size_t Query::get_index( void ) const
    {
        return m_pimpl->m_index;
    }
    
    size_t Query::get_limit( void ) const
    {
        return m_pimpl->m_limit;
    }
    
    Resources Query::get_resultset( void ) const
    {
        return m_pimpl->m_resultset;
    }
    
    set< string > Query::get_fields( void ) const
    {
        return m_pimpl->m_fields;
    }
    
    vector< string > Query::get_keys( void ) const
    {
        return m_pimpl->m_keys;
    }
    
    shared_ptr< Session > Query::get_session( void ) const
    {
        return m_pimpl->m_session;
    }
    
    multimap< string, Bytes > Query::get_inclusive_filters( void ) const
    {
        return m_pimpl->m_inclusive_filters;
    }
    
    multimap< string, Bytes > Query::get_exclusive_filters( void ) const
    {
        return m_pimpl->m_exclusive_filters;
    }
    
    void Query::set_error_code( const int value )
    {
        m_pimpl->m_error_code = value;
    }
    
    void Query::set_index( const size_t start )
    {
        m_pimpl->m_index = start;
    }
    
    void Query::set_limit( const size_t stop )
    {
        m_pimpl->m_limit = stop;
    }
    
    void Query::set_resultset( const Resources& values )
    {
        m_pimpl->m_resultset = values;
    }
    
    void Query::set_include( const Bytes& relationship )
    {
        m_pimpl->m_include = relationship;
    }
    
    void Query::set_key( const Bytes& value )
    {
        m_pimpl->m_keys.push_back( String::to_string( value ) );
    }
    
    void Query::set_key( const string& value )
    {
        m_pimpl->m_keys.push_back( value );
    }
    
    void Query::set_keys( const vector< string >& values )
    {
        m_pimpl->m_keys = values;
    }
    
    void Query::set_fields( const set< string >& values )
    {
        m_pimpl->m_fields = values;
    }
    
    void Query::set_session( const shared_ptr< Session >& value )
    {
        m_pimpl->m_session = value;
    }
    
    void Query::set_inclusive_filter( const string& name, const Bytes& value )
    {
        m_pimpl->m_inclusive_filters.insert( make_pair( name, value ) );
    }
    
    void Query::set_inclusive_filters( const multimap< string, Bytes >& values )
    {
        m_pimpl->m_inclusive_filters = values;
    }
    
    void Query::set_exclusive_filter( const string& name, const Bytes& value )
    {
        m_pimpl->m_exclusive_filters.insert( make_pair( name, value ) );
    }
    
    void Query::set_exclusive_filters( const multimap< string, Bytes >& values )
    {
        m_pimpl->m_exclusive_filters = values;
    }
}
