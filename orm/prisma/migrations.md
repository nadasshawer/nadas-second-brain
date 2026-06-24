## Schema Migrations

A **database migration** is like version control (Git) for the database structure. Instead of manually changing tables or running raw SQL commands inside the terminal, structural changes are written down in a code file.

- `migrate` → changes the database
#### Usage

- **Version Control:** Keeps a chronological history of the database changes on GitHub
- **Environment Sync:** Guarantees the local machine, the team, and the cloud server are identical
- **Error Prevention:** Automates SQL generation so we don't break anything typing manually
- **Testing Automation:** Instantly spins up fresh database environments to run automated tests
#### Create a Migration

```shell
npx prisma migrate dev
```
