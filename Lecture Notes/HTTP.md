See also: [[DNS]]
[[Cross Site Request Forgery Attack]]
# What It Is and How It Works
HTTP stands for "HyperText Transfer Protocol." It is a script used by servers and clients so that clients can request information and servers can return it. 
Clients will send a request line and headers, and the Server will send a status, header information, and body.

Nearly all websites use HTTP or HTTPS.

### HTTP is "stateless."
The server will maintain no information about past client requests.

### HTTP uses TCP
* The client initiates TCP connection to the server, port 80
* Server accepts TCP connection from client
### Every Step in Non-persistent HTTP
* Client makes a TCP connection request at port 80
* Server listening for a TCP connection through port 80 responds
* Client makes a request
* Server sends back data
* HTTP server closes TCP connection
* HTTP client receives response message containing html file and then displays the html. As the client parses the html file, it finds 10 referenced jpeg objects
* Steps 1-6 are repeated for each jpeg.
# Security Issues in HTTP
If you are watching youtube videos, your parents could find what videos you have been watching by looking at your HTTP requests.
Everything being sent through HTTP could be intercepted and read by an attacker if it is not encrypted.
# CDN (content delivery network)
Without this, if a person would want to connect to your server from India to the US, they would have to connect from a very far distance away. A CDN network has subsets of your server from the US in different places like France to serve as the middleman so that the client in India doesn't have to connect from as far away. 

# [[Cookies]]