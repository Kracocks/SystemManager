//
// Created by kracocks on 29/01/25.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

namespace model {
	struct Encrypt {
		/**
		 * Generate a private and public key for the encryption of sensitive data.
		 * It can be safe to delete the public key as it will be generated back but if you
		 * delete the private key and stored sensitive data you cannot recover them as it is
		 * the key to decrypt them.
		 * @return return true if the generation was done without problem
		 */
		static bool generateKeyPair();
		/**
		 * Encrypt a string using the public key
		 * @param input the input to be encrypted
		 * @param output the encrypted input
		 * @return return true if the encryption was done without problem
		 */
		static bool encrypt(const std::string &input, std::string *output = nullptr);
		/**
		 * decrypt a string using the private key
		 * @param input the input to be decrypted
		 * @param output the decrypted input
		 * @return return true if the decryption was done without problem
		 */
		static bool decrypt(const std::string &input, std::string *output = nullptr);
	};
}

#endif //FUNCTIONS_H
