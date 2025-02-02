//
// Created by kracocks on 12/01/25.
//

#ifndef IDENTIFIANT_H
#define IDENTIFIANT_H
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Encrypt.h"
#include "TokenGroup.h"

namespace model {
	struct Service;
	struct TokenGroup;

	template <typename Int=int, typename Str=std::string, typename Ser=Service, typename Bool=bool, typename TGroup=TokenGroup>
    requires std::same_as<Int, int> &&
    		 std::same_as<Str, std::string> &&
    		 std::same_as<Ser, Service> &&
    		 std::same_as<Bool, bool> &&
    		 std::same_as<TGroup, TokenGroup>
    class Identifiant {
        Int m_id;
        Str m_email;
        Str m_password;
        std::vector<Ser> m_services;
		std::vector<TGroup> m_token_groups;

    public:
        Identifiant() = delete;

        /**
         * Create a login with an ID, an email and a password
         * @param id ID of the login
         * @param email Email of the login
         * @param password password of the login
         * @param shouldEncrypt encrypt the password if it needs to be encrypted
         */
        Identifiant(Int &&id, Str &&email, Str &&password, Bool &&shouldEncrypt)
            : m_id(std::forward<Int>(id)),
              m_email(std::forward<Str>(email)),
              m_password(std::forward<Str>(password)),
              m_services({}),
			  m_token_groups({}) {
			if (shouldEncrypt) {
				std::string encrypted {};
				Encrypt::encrypt(email, &encrypted);
				password = encrypted;
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
        [[nodiscard]] std::vector<Ser> getServices() const {return m_services; }

		/**
		 * Get the Token Groups associated to the login
		 * @return Token Groups associated to the login
		 */
		[[nodiscard]] std::vector<TGroup> getTokenGroups() const {return m_token_groups;}

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
		 * Set the email of the login
		 * @param email New email of the login
		 */
		void setEmail(const Str &email) {m_email = std::move(email);}

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
        	Ser it = std::find(m_services.begin(), m_services.end(), service);
        	if (it != m_services.end()) {
        		m_services.erase(it);
        	}
        }

		/**
		 * Add a new token group to the login
		 * @param token_group New token group to associate to the login
		 */
		void addTokenGroup(const TGroup &&token_group) {m_token_groups.push_back(token_group); }

		/**
		 * Remove a token group associated to the login
		 * @param token_group Token group associated to the login
		 */
		void removeTokenGroup(const TGroup &&token_group) {
	        TGroup it = std::find(m_token_groups.begin(), m_token_groups.end(), token_group);
        	if (it != m_token_groups.end()) {
        		m_token_groups.erase(it);
        	}
        }

    	void display() const {
	        std::cout << "Email : " <<  m_email << "\tPassword : " << m_password << "\n";
        	for (const TGroup &group : m_token_groups) {
        		group.display();
        	}
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
