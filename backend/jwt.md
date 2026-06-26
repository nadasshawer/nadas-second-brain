## JWT (JSON Web Token)

**JWT** is a signed string the server issues at login; the client sends it back on every request so the API knows who the user is **without** storing sessions.

- Alternative to server-side sessions → **stateless auth**.
#### Structure

```text
HEADER.PAYLOAD.SIGNATURE
```

| Part          | Contains                                                          |
| ------------- | ----------------------------------------------------------------- |
| **Header**    | Algorithm (`HS256`, etc.)                                         |
| **Payload**   | Claims — data about the user (`id`, `stage`, `exp`)               |
| **Signature** | Hash signed with a secret key — proves token wasn't tampered with |
- Payload is **readable** (base64), not encrypted. Signature prevents forgery.
#### Flow

```text
login → server signs token → client stores it
      → client sends: Authorization: Bearer <token>
      → server jwt.verify(token, secret) → req.user
```
#### Access vs Refresh

- **Access token** → short-lived; sent on every API request
- **Refresh token** → long-lived; used only to get a new access token (rotation)
#### Status Codes (with auth middleware)

- **401 Unauthorized** → no token, invalid token, or expired
- **403 Forbidden** → valid token, but not allowed for this resource (often handled by separate [middleware](express-middleware.md) like stage gates)
#### In Express

```text
Authorization: Bearer eyJhbGciOiJIUzI1NiIs...
```

Middleware strips `Bearer `, runs `jwt.verify()`, attaches decoded user to `req.user`.
