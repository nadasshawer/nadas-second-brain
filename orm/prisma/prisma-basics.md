## Prisma

**Prisma** is an **ORM** (Object-Relational Mapper) for Node.js that maps TypeScript types and database tables so we can query in code instead of writing raw SQL everywhere.

- Python equivalent → Peewee ORM
- Works with [PostgreSQL](basics.md) and other databases (MySQL, SQLite, SQL Server)
- The app side is **JavaScript/TypeScript**
- The schema uses Prisma's own small DSL (`.prisma` files)
#### Mental Model

```text
schema.prisma   →  blueprint (tables, columns, enums)
       ↓
prisma migrate  →  versioned SQL applied to the database
       ↓
prisma generate →  auto-generated TypeScript client
       ↓
your API code   →  prisma.user.findMany()  // no raw SQL in routes
```

- **Schema + migrations** → go in Git (structure only)
- **Database rows** → stay on disk / remote host (never commit)
#### Key Terms

- **ORM** → maps code objects to DB tables
- **Schema** → blueprint of models, fields, and relations
- **Model** → one table (e.g. `User` → `users`)
- **[Migration](migrations.md)** → saved SQL change to the DB structure (like a git commit for tables)
- **Prisma Client** → generated TS code imported to query th1e DB
- **Enum** → fixed set of allowed values (e.g. user `stage`)
#### Prisma vs Raw SQL
| Raw SQL in app                  | Prisma                          |
| ------------------------------- | ------------------------------- |
| String queries, easy to typo    | Type-checked queries            |
| Manual type definitions         | Types generated from schema     |
| You write `ALTER TABLE` by hand | Migrations track schema history |

