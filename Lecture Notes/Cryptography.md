Communications across networks is fundamentally insecure. That is why we must encrypt data that is sent across the web.
# Symmetric
# Asymmetric
Everyone has public keys that can be used to encrypt data, certain people have private keys to decrypt data.

### Man-in-the-Middle Attack
Were someone to send you a public key, some adversary could intercept it before it gets to you and send you their own public key. Then, when you send encrypted data back, the adversary can intercept the data and decrypt it themselves with their corresponding private key.

In the below case, Mallory is the adversary intercepting information and giving Alice a different public key than what Bob sent.
![[mima-2.jpg]] 
When executed correctly, there is no way to determine if the public key that got sent out to Alice was actually the public key that Alice received. 

##### What is the solution?
* Find a trusted party to verify the identity
	* Called a [[Certificate Authority (CA)]]
* Bind an identity to a public key in a certificate
* The certificate cannot be forged or tampered with (using a digital signature)
The CA will create a certificate that verifies the information and will provide a signature verifying the certificate. 
