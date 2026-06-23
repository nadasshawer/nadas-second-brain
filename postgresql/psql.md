## psql

`psql` is the terminal client for PostgreSQL — it sends SQL to the server ([[basics|concepts]]). Use [[local-setup]] if you still need install, database, and user setup.
#### Connect

```powershell
psql -U postgres -h localhost
psql -U myapp_user -d myapp_dev -h localhost
```

| Flag | Meaning |
|------|---------|
| `-U` | Username (role) |
| `-d` | Database name |
| `-h localhost` | Server on this machine |
| Port `5432` | Default; omit when using default |
#### Read Your Prompt
| Prompt        | Meaning                                  |
| ------------- | ---------------------------------------- |
| `postgres=#`  | Superuser on default `postgres` database |
| `myapp_dev=#` | Superuser on your project database       |
| `myapp_dev=>` | Normal app user on project database      |

- `#` at end → superuser session
- `=>` at end → normal user session
#### Verify Where You Are

```sql
SELECT current_database(), current_user;
```

- After `\c myapp_dev` as superuser → database name + `postgres`
- After login as app user → database name + app username
#### Meta-Commands (backslash shortcuts)

psql-only shortcuts — not SQL:

| Command | Action |
|---------|--------|
| `\c dbname` | Connect to a different database |
| `\l` | List all databases |
| `\du` | List all users/roles |
| `\q` | Quit psql |
| `\?` | Help for meta-commands |
| `\h CREATE DATABASE` | Help for a SQL command |
