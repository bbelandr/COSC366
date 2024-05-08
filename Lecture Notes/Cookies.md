Cookies are how we send information from client to server and server to client.
Cookies are key value pairs.
# How long do cookies last?
Usually, sites set expiration dates for cookies. Google is holding cookies until 2038 and then will go to a two year expiration. They last until the user clears them. 

Cookies without an expiration date last for the browser session.

# Why use cookies?
* Personalization
	* Anonymous users can customize your website.
* Tracking Users
	* Advertisers want to know your behavior
	* Build a profile across different websites
		* An advertiser can know what you did on another site through cookies
# Session Hijacking
Sending cookies over unencrypted HTTP is a very bad idea.
* If anyone sees the cookie, they can use it to hijack the user's session
* The attacker can send the victim's cookie as if it was their own
Firesheep (2010) did this on firefox browsers.
* Cookies were being sent over HTTP instead of HTTPS, which meant that attackers could eavesdrop on your connection to sites like twitter and login to your account through your cookies.
### Secure cookies
The secure cookie attribute prevents cookies from being sent over unencrypted HTTP connections.
```
Set-Cookie: key=value; 
```
The above makes the cookie only be communicated over HTTPS, the secure version of HTTP. 