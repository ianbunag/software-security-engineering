import hashlib
import os

def hash_password_pbkdf2(plain_text_password: str):
    # Generate a 16-byte cryptographically secure random salt
    salt = os.urandom(16)

    # Hash using PBKDF2 with HMAC-SHA256 and 600,000 iterations
    hashed = hashlib.pbkdf2_hmac(
        'sha256',
        plain_text_password.encode('utf-8'),
        salt,
        600000 # High iteration count slows down attackers
    )

    # Return both so you can save both fields into your database row
    return salt, hashed

def verify_password_pbkdf2(plain_text_password: str, stored_salt: bytes, stored_hash: bytes) -> bool:
    # Re-hash the login attempt using the exact same salt and iterations
    new_hash = hashlib.pbkdf2_hmac(
        'sha256',
        plain_text_password.encode('utf-8'),
        stored_salt,
        600000
    )

    if (stored_hash == new_hash):
        return 1
    else:
        return 0
