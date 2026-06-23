## Local Setup (Windows)

Install PostgreSQL locally and create a dev database + app user. Assumes [[basics|PostgreSQL basics]]; connect with [[psql]] once the server is running.
#### Install

- Download from [postgresql.org/download/windows](https://www.postgresql.org/download/windows/)
- Set superuser (`postgres`) password at install
- Default port → `5432`
#### PATH Fix

If [[psql]] is not recognized, add the PostgreSQL `bin` folder to User PATH:

```powershell
# Example path (version may differ)
C:\Program Files\PostgreSQL\18\bin
```

Verify:

```powershell
psql --version
```

- Always open a **new** terminal after changing PATH
#### Create Database and App User

Login as superuser:

```powershell
psql -U postgres -h localhost
```

Run:

```sql
CREATE DATABASE myapp_dev;

CREATE USER myapp_user WITH ENCRYPTED PASSWORD 'your_password_here';

GRANT ALL PRIVILEGES ON DATABASE myapp_dev TO myapp_user;

\c myapp_dev

GRANT ALL ON SCHEMA public TO myapp_user;
ALTER DEFAULT PRIVILEGES IN SCHEMA public GRANT ALL ON TABLES TO myapp_user;
```

Replace `myapp_dev` / `myapp_user` with your project names.
#### Why Each Step?

- `CREATE DATABASE` → empty container for your project's tables
- `CREATE USER` → dedicated login for the application (not admin)
- `GRANT ... DATABASE` → allows user to connect to that database
- `\c dbname` → switch into that database before schema-level grants
- `GRANT ... SCHEMA public` → allows user to create tables (required on PostgreSQL 15+)
#### Verify App Login

```powershell
psql -U myapp_user -d myapp_dev -h localhost
```

```sql
SELECT current_database(), current_user;
```

**Expected:** your database name + app username.

#### Common Pitfalls
| Problem                               | Fix                                               |
| ------------------------------------- | ------------------------------------------------- |
| `psql` not recognized                 | Add PostgreSQL `bin` to PATH; new terminal        |
| Wrong user/database on SELECT         | `\c dbname` or `\q` and re-login with `-U` / `-d` |
| `permission denied for schema public` | Run GRANT on `public` schema                      |
| `database already exists`             | Safe to ignore if re-running setup                |
