# language: en

Feature: If-Modified-Since request-header field
    In order to ignore conditional requests 
    As a exchange developer
    I want to return a normal status for the If-Modified-Since request-header field

    Scenario Outline: Date if-modified-since request-header field.
        Given I have started a message exchange
        And I perform a HTTP "POST" request to "/queues" with headers "Content-Type: application/json, Accept: application/json, Host: localhost:1984":
        """
        " { "data": {                                        "
        "     "name": "acceptance test queue",               "
        "     "key": "f240cf49-e965-4fa7-b14c-4b5d8ba469cf"  "
        "   }                                                "
        " }                                                  "
        """
        And I perform a HTTP "POST" request to "/subscriptions" with headers "Content-Type: application/json, Accept: application/json, Host: localhost:1984":
        """
        " { "data": {                                              "
        "     "name": "acceptance test consumer",                  "
        "     "endpoint": "http://localhost:1985",                 "
        "     "queues": [ "f240cf49-e965-4fa7-b14c-4b5d8ba469cf" ] "
        "   }                                                      "
        " }                                                        "
        """
        When I perform a HTTP "POST" request to "/messages" with headers "Content-Type: text/plain, Accept: application/json, Host: localhost:1984, If-Modified-Since: Sat, 29 Oct 1994 19:43:31 GMT":
        """
        " ftp://localhost/reading "
        """
        Then I should see a response status code of "202" "Accepted"
        And I should see a "Server" header value "corvusoft/restq"
        And I should see a "Connection" header value "close"
        And I should see a "Date" header value
        And I should see a "Expires" header value "0"
        And I should see a "Pragma" header value "no-cache"
        And I should see a "Cache-Control" header value "private,max-age=0,no-cache,no-store"
        And I should see a "Vary" header value "Accept,Accept-Encoding,Accept-Charset,Accept-Language"
        And I should see a "Accept-Ranges" header value "none"
        And I should see a "Allow" header value "OPTIONS"
        And I should see a "Location" header value
        And I should not see a "ETag" header value
        And I should not see a "Content-Type" header value
        And I should not see a "Content-Length" header value
        And I should not see a "Content-MD5" header value
        And I should not see a "Last-Modified" header value
        And I should not see a "WWW-Authenticate" header value
        And I should not see a "Trailer" header value
        And I should not see a "Warning" header value
        And I should not see a "Content-Range" header value
        And I should not see a "Content-Encoding" header value
        And I should not see a "Content-Language" header value
        And I should not see a "Content-Location" header value
        And I should not see a "Retry-After" header value
        And I should not see a "Age" header value
        And I should not see a "Via" header value
        And I should not see a "Upgrade" header value
        And I should not see a "Transfer-Encoding" header value
        And I should not see a "Proxy-Authentication" header value
        And I should see an empty response

    Scenario Outline: Malformed if-modified-since request-header field.
        Given I have started a message exchange
        And I perform a HTTP "POST" request to "/queues" with headers "Content-Type: application/json, Accept: application/json, Host: localhost:1984":
        """
        " { "data": {                                        "
        "     "name": "acceptance test queue",               "
        "     "key": "eed62023-edb4-434d-b477-722355617fc3"  "
        "   }                                                "
        " }                                                  "
        """
        And I perform a HTTP "POST" request to "/subscriptions" with headers "Content-Type: application/json, Accept: application/json, Host: localhost:1984":
        """
        " { "data": {                                              "
        "     "name": "acceptance test consumer",                  "
        "     "endpoint": "http://localhost:1985",                 "
        "     "queues": [ "eed62023-edb4-434d-b477-722355617fc3" ] "
        "   }                                                      "
        " }                                                        "
        """
        When I perform a HTTP "POST" request to "/messages" with headers "Content-Type: text/plain, Accept: application/json, Host: localhost:1984, If-Modified-Since: 3u9c8duco":
        """
        " ftp://localhost/reading "
        """
        Then I should see a response status code of "202" "Accepted"
        And I should see a "Server" header value "corvusoft/restq"
        And I should see a "Connection" header value "close"
        And I should see a "Date" header value
        And I should see a "Expires" header value "0"
        And I should see a "Pragma" header value "no-cache"
        And I should see a "Cache-Control" header value "private,max-age=0,no-cache,no-store"
        And I should see a "Vary" header value "Accept,Accept-Encoding,Accept-Charset,Accept-Language"
        And I should see a "Accept-Ranges" header value "none"
        And I should see a "Allow" header value "OPTIONS"
        And I should see a "Location" header value
        And I should not see a "ETag" header value
        And I should not see a "Content-Type" header value
        And I should not see a "Content-Length" header value
        And I should not see a "Content-MD5" header value
        And I should not see a "Last-Modified" header value
        And I should not see a "WWW-Authenticate" header value
        And I should not see a "Trailer" header value
        And I should not see a "Warning" header value
        And I should not see a "Content-Range" header value
        And I should not see a "Content-Encoding" header value
        And I should not see a "Content-Language" header value
        And I should not see a "Content-Location" header value
        And I should not see a "Retry-After" header value
        And I should not see a "Age" header value
        And I should not see a "Via" header value
        And I should not see a "Upgrade" header value
        And I should not see a "Transfer-Encoding" header value
        And I should not see a "Proxy-Authentication" header value
        And I should see an empty response

    Scenario Outline: Empty if-modified-since request-header field.
        Given I have started a message exchange
        And I perform a HTTP "POST" request to "/queues" with headers "Content-Type: application/json, Accept: application/json, Host: localhost:1984":
        """
        " { "data": {                                        "
        "     "name": "acceptance test queue",               "
        "     "key": "3f0f8cd7-31ae-4ea0-b4a6-bdfcaab69999"  "
        "   }                                                "
        " }                                                  "
        """
        And I perform a HTTP "POST" request to "/subscriptions" with headers "Content-Type: application/json, Accept: application/json, Host: localhost:1984":
        """
        " { "data": {                                              "
        "     "name": "acceptance test consumer",                  "
        "     "endpoint": "http://localhost:1985",                 "
        "     "queues": [ "3f0f8cd7-31ae-4ea0-b4a6-bdfcaab69999" ] "
        "   }                                                      "
        " }                                                        "
        """
        When I perform a HTTP "POST" request to "/messages" with headers "Content-Type: text/plain, Accept: application/json, Host: localhost:1984, If-Modified-Since: ":
        """
        " ftp://localhost/reading "
        """
        Then I should see a response status code of "202" "Accepted"
        And I should see a "Server" header value "corvusoft/restq"
        And I should see a "Connection" header value "close"
        And I should see a "Date" header value
        And I should see a "Expires" header value "0"
        And I should see a "Pragma" header value "no-cache"
        And I should see a "Cache-Control" header value "private,max-age=0,no-cache,no-store"
        And I should see a "Vary" header value "Accept,Accept-Encoding,Accept-Charset,Accept-Language"
        And I should see a "Accept-Ranges" header value "none"
        And I should see a "Allow" header value "OPTIONS"
        And I should see a "Location" header value
        And I should not see a "ETag" header value
        And I should not see a "Content-Type" header value
        And I should not see a "Content-Length" header value
        And I should not see a "Content-MD5" header value
        And I should not see a "Last-Modified" header value
        And I should not see a "WWW-Authenticate" header value
        And I should not see a "Trailer" header value
        And I should not see a "Warning" header value
        And I should not see a "Content-Range" header value
        And I should not see a "Content-Encoding" header value
        And I should not see a "Content-Language" header value
        And I should not see a "Content-Location" header value
        And I should not see a "Retry-After" header value
        And I should not see a "Age" header value
        And I should not see a "Via" header value
        And I should not see a "Upgrade" header value
        And I should not see a "Transfer-Encoding" header value
        And I should not see a "Proxy-Authentication" header value
        And I should see an empty response
