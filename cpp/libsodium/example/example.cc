#include <sodium.h>
#include <string.h>

#include <string>
#include <vector>
#include <iostream>

int main(void) {
  if (sodium_init() < 0) {
    return -1;
  }

  const std::string message = "Hello, Libsodium!";

  // Buffer for ciphertext: crypto_secretbox_MACBYTES extra bytes for
  // authentication tag
  size_t len = crypto_secretbox_MACBYTES + message.length();
  std::vector<unsigned char> ciphertext(len);
  std::vector<unsigned char> key(crypto_secretbox_KEYBYTES);
  std::vector<unsigned char> nonce(crypto_secretbox_NONCEBYTES);

  // Securely fill buffers with random data
  randombytes_buf(&key[0], key.size());
  randombytes_buf(&nonce[0], nonce.size());

  crypto_secretbox_easy(&ciphertext[0], (const unsigned char*)&message[0],
                        message.length(), &nonce[0], &key[0]);

  std::cout << "Message successfully encrypted." << std::endl;

  std::string decrypted(message.length(), '\0');

  if (crypto_secretbox_open_easy((unsigned char*)&decrypted[0], &ciphertext[0], ciphertext.size(),
                                 &nonce[0], &key[0]) != 0) {
    std::cerr << "Decryption failed or message corrupted!" << std::endl;
    return 1;
  }

  std::cout << decrypted << std::endl;

  sodium_memzero(&key[0], key.size());
  return 0;
}
