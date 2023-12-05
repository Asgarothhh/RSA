# RSA
The RSA algorithm is a widely used public-key encryption method. It works on the principle of using two keys - a public key and a private key. The public key is used for encryption while the private key is used for decryption.

To encrypt a message, the sender uses the recipient's public key to transform the message into an unreadable format. Only the recipient, who has the corresponding private key, can decrypt the message and read its contents.

The RSA algorithm is based on the mathematical properties of large prime numbers. The security of the algorithm lies in the fact that it is computationally infeasible to factorize large prime numbers.

To generate the keys, the sender selects two large prime numbers and multiplies them together to obtain a composite number. This composite number is used as part of both the public and private keys. The other parts of the keys are derived from mathematical functions that use the prime numbers.

The RSA algorithm is widely used in secure communication systems, such as online banking and e-commerce. It provides a secure method for transmitting sensitive information over public networks.
****************************************************************************************************************
This is a simple example of encryption using the RSA system. This code did not turn out to be particularly optimized (at least due to the use of 3 arrays (!), which could have been avoided). But I gladly accept all constructive amendments and suggestions!
