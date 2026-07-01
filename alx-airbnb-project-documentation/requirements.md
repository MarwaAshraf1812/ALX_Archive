# Backend Feature Requirements
This document outlines the key requirements for implementing the backend features of the Airbnb Clone. Each feature is described with its purpose, API endpoints, validation rules, and expected performance criteria.


## 1. User Authentication
### Purpose
Allow users to register, login, and logout from the application.

### API Endpoints
- **POST /register**: Create a new user account.
- **POST /login**: Authenticate an existing user.
- **POST /logout**: Invalidate the user's session.
- **GET /user**: Retrieve the currently authenticated user's details.
- **PATCH /user**: Update the currently authenticated user's details.
- **DELETE /user**: Delete the currently authenticated user's account.
- **Input**:
     ```json
     {
       "email": "user@example.com",
       "password": "securepassword",
       "role": "guest" // or "host"
     }
     ```
   - **Output** (Success):
     ```json
     {
       "message": "Registration successful",
       "userId": "12345"
     }
     ```
   - **Output** (Failure):
     ```json
     {
       "error": "Email already in use"
     }
     ```

      ```json
     {
       "email": "user@example.com",
       "password": "securepassword"
     }
     ```
   - **Output** (Success):
     ```json
     {
       "message": "Login successful",
       "token": "JWT_TOKEN_HERE",
       "userId": "12345",
       "role": "guest"
     }
     ```
   - **Output** (Failure):
     ```json
     {
       "error": "Invalid email or password"
     }
     ```
### Validation Rules
- **Username**: Must be unique, between 3 and 20 characters, and contain only alphanumeric
- **Email**: Must be unique and follow the standard email format.
- **Password**: Must be between 8 and 128 characters and contain at least one digit,
one uppercase letter, one lowercase letter, and one special character.

## 2. Profile Management
   - **Endpoint**: `PUT /api/v1/users/:userId`
   - **Input**:
     ```json
     {
       "profilePhoto": "base64EncodedString",
       "contactInfo": {
         "phone": "+123456789",
         "address": "123 Street, City, Country"
       },
       "preferences": {
         "currency": "USD",
         "language": "en"
       }
     }
     ```
   - **Output** (Success):
     ```json
     {
       "message": "Profile updated successfully"
     }
     ```
   - **Validation Rules**:
     - `profilePhoto`: Optional, must be a valid base64 string if provided.
     - `contactInfo.phone`: Optional, must be a valid phone number.
     - `preferences.currency`: Optional, must be a valid ISO currency code.
     - `preferences.language`: Optional, must be a valid ISO language code.

## 3. Listing Management
### Purpose
Allow users to create, read, update, and delete listings.
### API Endpoints
- **POST /listings**: Create a new listing.
- **GET /listings**: Retrieve a list of all listings.
- **GET /listings/:id**: Retrieve a specific listing by ID.
- **PATCH /listings/:id**: Update a specific listing.
- **DELETE /listings/:id**: Delete a specific listing.

```json
     {
       "title": "Cozy Apartment in Downtown",
       "description": "A beautiful apartment located in the heart of the city.",
       "location": "123 Main St, City, Country",
       "price": 120,
       "amenities": ["WiFi", "Pool", "Parking"],
       "availability": {
         "startDate": "2024-01-01",
         "endDate": "2024-12-31"
       }
     }
     ```
   - **Output** (Success):
     ```json
     {
       "message": "Property listed successfully",
       "propertyId": "67890"
     }
```
### Validation Rules
- **Title**: Must be between 3 and 50 characters.
- **Description**: Must be between 10 and 2000 characters.
- **Price**: Must be a positive number.
- **Location**: Must be a valid geographic location.

## 4. Booking Management
### Purpose
Allow users to create, read, update, and delete bookings.
### API Endpoints
- **POST /bookings**: Create a new booking.
- **GET /bookings**: Retrieve a list of all bookings.
- **GET /bookings/:id**: Retrieve a specific booking by ID.
- **PATCH /bookings/:id**: Update a specific booking.
- **DELETE /bookings/:id**: Delete a specific booking.
  ```json
     {
       "propertyId": "67890",
       "guestId": "12345",
       "startDate": "2024-02-01",
       "endDate": "2024-02-10"
     }
     ```
   - **Output** (Success):
     ```json
     {
       "message": "Booking created successfully",
       "bookingId": "abcdef"
     }
    ```
### Validation Rules
- **Start Date**: Must be a valid date in the future.
- **End Date**: Must be a valid date in the future and after the start date.
- **Listing ID**: Must match the ID of an existing listing.

## 5. Payment Management
### Purpose
Allow users to create, read, update, and delete payments.
### API Endpoints
- **POST /payments**: Create a new payment.
- **GET /payments**: Retrieve a list of all payments.
- **GET /payments/:id**: Retrieve a specific payment by ID.
- **PATCH /payments/:id**: Update a specific payment.
- **DELETE /payments/:id**: Delete a specific payment.
### Validation Rules
- **Amount**: Must be a positive number.
- **Listing ID**: Must match the ID of an existing listing.
- **Booking ID**: Must match the ID of an existing booking.


## **Performance Criteria**
- **Response Time**: All APIs must respond within 300ms for 95% of requests under normal load.
- **Concurrency**: Support at least 100 concurrent users.
- **Data Validation**: Input validation must be strict to prevent injection attacks or invalid data storage.
- **Scalability**: The backend must handle 10,000 users and 1,000 bookings per day without performance degradation.

