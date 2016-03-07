/*
 * Copyright 2014-2016, Corvusoft Ltd, All Rights Reserved.
 */

#ifndef _RESTQ_DETAIL_EXCHANGE_IMPL_H
#define _RESTQ_DETAIL_EXCHANGE_IMPL_H 1

//System Includes
#include <map>
#include <list>
#include <ctime>
#include <string>
#include <memory>
#include <utility>
#include <stdexcept>

//Project Includes
#include <corvusoft/restq/byte.hpp>
#include <corvusoft/restq/logger.hpp>

//External Includes
#include <corvusoft/restbed/rule.hpp>
#include <corvusoft/restbed/service.hpp>
#include <corvusoft/restbed/session.hpp>

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restq
{
    //Forward Declarations
    class Logger;
    class Encoder;
    class Settings;
    class Exchange;
    class Repository;
    
    namespace detail
    {
        //Forward Declarations
        
        class ExchangeImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                ExchangeImpl( void );
                
                virtual ~ExchangeImpl( void );
                
                //Functionality
                void start( void );
                
                void log( const Logger::Level level, const std::string& message ) const;
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                std::time_t m_boot_time;
                
                std::shared_ptr< Logger > m_logger;
                
                std::shared_ptr< Repository > m_repository;
                
                std::shared_ptr< const Settings > m_settings;
                
                std::shared_ptr< restbed::Service > m_service;
                
                std::function< void ( void ) > m_ready_handler;
                
                std::shared_ptr< restbed::Rule > m_key_rule;
                
                std::shared_ptr< restbed::Rule > m_keys_rule;
                
                std::shared_ptr< restbed::Rule > m_paging_rule;
                
                std::shared_ptr< restbed::Rule > m_content_type_rule;
                
                std::shared_ptr< restbed::Rule > m_content_encoding_rule;
                
                std::map< std::string, std::shared_ptr< Formatter > > m_formats;
                
            protected:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                
            private:
                //Friends
                
                //Definitions
                static const Bytes PENDING;
                
                static const Bytes REJECTED;
                
                static const Bytes INFLIGHT;
                
                static const Bytes DISPATCHED;
                
                static const Bytes QUEUE;
                
                static const Bytes STATE;
                
                static const Bytes MESSAGE;
                
                static const Bytes SUBSCRIPTION;
                
                //Constructors
                ExchangeImpl( const ExchangeImpl& original ) = delete;
                
                //Functionality
                bool is_valid( const std::pair< const std::string, const std::string >& header ) const;
                
                bool is_invalid( const std::multimap< std::string, Bytes >& values, const Bytes& type ) const;
                
                void remove_reserved_words( std::multimap< std::string, Bytes >& value ) const;
                
                void remove_reserved_words( std::list< std::multimap< std::string, Bytes > >& values ) const;
                
                std::multimap< std::string, Bytes > make_message( const std::shared_ptr< restbed::Session >& session ) const;
                
                void setup_ruleset( void );
                
                void setup_queue_resource( void );
                
                void setup_queues_resource( void );
                
                void setup_message_resource( void );
                
                void setup_messages_resource( void );
                
                void setup_asterisk_resource( void );
                
                void setup_subscription_resource( void );
                
                void setup_subscriptions_resource( void );
                
                void dispatch( void );
                
                void create_message_handler( const std::shared_ptr< restbed::Session > session );
                
                void create_resource_handler( const std::shared_ptr< restbed::Session > session, const Bytes& type );
                
                void read_resource_handler( const std::shared_ptr< restbed::Session > session, const Bytes& type );
                
                void update_resource_handler( const std::shared_ptr< restbed::Session > session, const Bytes& type );
                
                void delete_resource_handler( const std::shared_ptr< restbed::Session > session, const Bytes& type );
                
                void asterisk_resource_handler( const std::shared_ptr< restbed::Session > session );
                
                void options_resource_handler( const std::shared_ptr< restbed::Session > session, const Bytes& type, const std::string& options );
                
                void method_not_allowed_handler( const std::shared_ptr< restbed::Session > session );
                
                void method_not_implemenented_handler( const std::shared_ptr< restbed::Session > session );
                
                void internal_server_error_handler( const int status, const std::exception& error, const std::shared_ptr< restbed::Session > session );
                
                //Getters
                
                //Setters
                
                //Operators
                ExchangeImpl& operator =( const ExchangeImpl& value ) = delete;
                
                //Properties
        };
    }
}

#endif  /* _RESTQ_DETAIL_EXCHANGE_IMPL_H */