## PostgreSQL Basics

- **PostgreSQL** is a relational database; stores structured data in tables (rows and columns)
- Query language → **SQL** (Structured Query Language)
- Strong choice when you need concurrent clients, background jobs, complex queries, and production-grade ACID guarantees
#### Server vs Client

- **Server** → runs in the background on your machine (Windows service, e.g. `postgresql-x64-18`)
- **Client (`psql`)** → terminal program that sends SQL to the server — see [[psql]] for commands
- Think: server = kitchen, `psql` = ordering at the counter
#### Key Terms

- **Database** → named container for a project's data
- **Role / User** → login identity with permissions
- **Schema** → namespace inside a database where tables live (default: `public`)
- **Superuser** → admin role with full control (default: `postgres`)
#### Dev Setup Best Practices

On Windows, follow [[local-setup]] to install the server and create a database + app user.

- **Separate database per project** → isolates data from other work on the same server
- **Separate app user** → application gets limited permissions; not full admin access
- **`public` schema grants** → PostgreSQL 15+ requires explicit grants before a non-admin user can create tables
#### Connection String Format

```text
postgresql://USER:PASSWORD@HOST:PORT/DATABASE
```

Example:

```text
postgresql://myapp_user:your_password@localhost:5432/myapp_dev
```

| Part | Typical value |
|------|---------------|
| Protocol | `postgresql://` |
| User | App-specific role (not superuser) |
| Host | `localhost` (local dev) |
| Port | `5432` (default) |
| Database | Project database name |
