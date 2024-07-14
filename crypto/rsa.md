# RSA

### generate key

1. select 2 prime number $P$, $Q$
2. compute product $N = P * Q$
3. compute totient $T = (P-1) * (Q-1)$
4. select public key $E$
  - must be prime
  - must be less than totient
  - must not be a factor of the totient
5. select private key $D$
  - product of $D$ and $E$, divided by $T$ must result in a remainder of 1
  - $(D * E) \mod T = 1$

### Encryption with public key

$Message^E \mod N = Cipher Text$

### Decryption with private key

$Cipher^D \mod N = Message$

or 

### Encryption with private key

$Message^D \mod N = Cipher Text$

### Decryption with public key

$Cipher^E \mod N = Message$
