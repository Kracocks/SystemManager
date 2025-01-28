//
// Created by kracocks on 12/01/25.
//

#ifndef IDENTIFIANT_H
#define IDENTIFIANT_H
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <openssl/sha.h>

namespace model {
	struct Service;

	template <typename Int=int, typename Str=std::string, typename Ser=Service, typename Bool=bool>
    requires std::same_as<Int, int> && std::same_as<Str, std::string> && std::same_as<Ser, Service> && std::same_as<Bool, bool>
    class Identifiant {
        Int m_id;
        Str m_email;
        Str m_password;
        std::vector<Ser> m_services;

		void encrypt(Str &&password) {
			// TODO: make the encryption
			return m_email + password + m_id;
        }

    	Str decrypt(Str &&password) {
			// TODO :Make the decryption
			return m_email - password - m_id;
        }

    public:
        Identifiant() = delete;

        /**
         * Create a login with an ID, an email and a password
         * @param id ID of the login
         * @param email Email of the login
         * @param password password of the login
         */
        Identifiant(Int &&id, Str &&email, Str &&password, Bool &&shouldEncrypt)
            : m_id(std::forward<Int>(id)),
              m_email(std::forward<Str>(email)),
              m_password(std::forward<Str>(password)),
              m_services({}) {
			if (shouldEncrypt) {
				std::cout << "Encrypting..." << std::endl;
			}
        }

		Identifiant(const Int &id, const Str &email, const Str &password, const Bool &shouldEncrypt)
			: m_id(id),
			  m_email(email),
			  m_password(password),
			  m_services({}) {
			if (shouldEncrypt) {
				std::cout << "Encrypting..." << std::endl;
			}
        }

        /**
         * Get the ID of the login
         * @return ID of the login
         */
        [[nodiscard]] Int getId() const {return m_id;}

        /**
         * Get the email of the login
         * @return Email of the login
         */
        [[nodiscard]] Str getEmail() const {return m_email;}

        /**
         * Get the password of the login
         * @return Password of the login
         */
        [[nodiscard]] Str getPassword() const {return m_password;}

        /**
         * Get the Services associated to the login
         * @return Services associated to the login
         */
        [[nodiscard]] std::vector<Ser> getServices() const {return m_services;}

        /**
         * Set the ID of the login
         * @param id New ID of the login
         */
        void setID(const Int &&id) {m_id = std::move(id);}

        /**
         * Set the email of the login
         * @param email New email of the login
         */
        void setEmail(const Str &&email) {m_email = std::move(email);}

        /**
         * Set the password of the login
         * @param password New password of the login
         */
        void setPassword(const Str &&password) {m_password = std::move(password);}

        /**
         * Add a new service to the login
         * @param service New service to associate to the login
         */
        void addService(const Ser &&service) {m_services.push_back(service);}

        /**
         * Remove a service associated to the login
         * @param service Service associated to the login
         */
        void removeService(const Ser &&service) {
        	auto it = std::find(m_services.begin(), m_services.end(), service);
        	if (it != m_services.end()) {
        		m_services.erase(it);
        	}
        }

    	void display() const {
	        std::cout << "Email : " <<  m_email << "\tPassword : " << m_password << "\n";
        }

        /**
         * Compare two logins
         * @param other Login to compare
         * @return True if the two objects are the same
         */
        bool operator==(const Identifiant &other) const {
            return m_email == other.m_email && m_password == other.m_password;
        }
    };

} // model

#endif //IDENTIFIANT_H
