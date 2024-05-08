# CA Setup
* The CA will be called ModelCA
* We need to set up the following for ModelCA
	* Generate public/private key pair
	* Create a X.509 certificate (who is going to sign it?)
	* We assume ModelCA is a root CA, so it is going to sign the certificate itself, so it is self-signed
* This command will generate a self-signed X.509 certificate (check the notes, this command in unfinished)
```
openssl req -x509 -newkey rsa:4096 -sha256 -days 3650
	-keyout modelCA_key.pem -out modelCA_cert
```
Since ModelCA's certificate is self-signed, how is it verified?