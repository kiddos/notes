#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using uchar = unsigned char;

int encrypt(std::vector<uchar>& plaintext, uchar* key, uchar* iv,
            std::vector<uchar>& ciphertext) {
  EVP_CIPHER_CTX* ctx;

  // Create and initialize the context
  if (!(ctx = EVP_CIPHER_CTX_new())) {
    ERR_print_errors_fp(stderr);
    return 0;
  }

  // Initialize the encryption operation with AES-256-CBC
  if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
    ERR_print_errors_fp(stderr);
    return 0;
  }

  // Provide the message to be encrypted, and obtain the encrypted output
  int len = 0;
  ciphertext.resize(plaintext.size() * 8);
  if (EVP_EncryptUpdate(ctx, &ciphertext[0], &len, &plaintext[0],
                        plaintext.size()) != 1) {
    ERR_print_errors_fp(stderr);
    return 0;
  }
  int ciphertext_len = len;

  // Finalize the encryption
  if (1 != EVP_EncryptFinal_ex(ctx, &ciphertext[0] + len, &len)) {
    ERR_print_errors_fp(stderr);
    return 0;
  }
  ciphertext_len += len;
  ciphertext.resize(ciphertext_len);

  // Clean up
  EVP_CIPHER_CTX_free(ctx);
  return ciphertext_len;
}

int decrypt(std::vector<uchar>& ciphertext, unsigned char* key,
            unsigned char* iv, std::vector<uchar>& plaintext) {
  EVP_CIPHER_CTX* ctx;

  // Create and initialize the context
  if (!(ctx = EVP_CIPHER_CTX_new())) {
    ERR_print_errors_fp(stderr);
    return 0;
  }

  // Initialize the decryption operation
  if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
    ERR_print_errors_fp(stderr);
    return 0;
  }

  // Provide the message to be decrypted, and obtain the plaintext output
  int len = 0;
  plaintext.resize(ciphertext.size() * 8);
  if (EVP_DecryptUpdate(ctx, &plaintext[0], &len, &ciphertext[0],
                        ciphertext.size()) != 1) {
    ERR_print_errors_fp(stderr);
    return 0;
  }
  int plaintext_len = len;

  // Finalize the decryption
  if (EVP_DecryptFinal_ex(ctx, &plaintext[0] + len, &len) != 1) {
    ERR_print_errors_fp(stderr);
    return 0;
  }
  plaintext_len += len;
  plaintext.resize(plaintext_len);

  // Clean up
  EVP_CIPHER_CTX_free(ctx);
  return plaintext_len;
}

int main(void) {
  std::string text =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod "
      "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim "
      "veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea "
      "commodo consequat. Duis aute irure dolor in reprehenderit in voluptate "
      "velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint "
      "occaecat cupidatat non proident, sunt in culpa qui officia deserunt "
      "mollit anim id est laborum.";
  std::vector<uchar> plaintext(text.begin(), text.end());
  std::vector<uchar> ciphertext;

  // Key and IV (Initialization Vector)
  uchar key[32] = {0};  // 256 bits for AES-256
  uchar iv[16] = {0};   // 128 bits for AES block size

  // Generate random key and IV
  if (RAND_bytes(key, sizeof(key)) != 1 || RAND_bytes(iv, sizeof(iv)) != 1) {
    ERR_print_errors_fp(stderr);
    return 0;
  }

  int ciphertext_len = encrypt(plaintext, key, iv, ciphertext);
  std::cout << "Ciphertext (%d bytes): " << ciphertext_len << std::endl;
  for (int i = 0; i < ciphertext_len; ++i) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");

  std::vector<uchar> decrypted;
  int decryptedtext_len = decrypt(ciphertext, key, iv, decrypted);
  assert(decryptedtext_len > 0);

  std::string decryptedtext(decrypted.begin(), decrypted.end());
  std::cout << "decrypted: " << decryptedtext << std::endl;

  assert(decryptedtext == text);
  return 0;
}
