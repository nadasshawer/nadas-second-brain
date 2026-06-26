## `schema.prisma` 

The `prisma/schema.prisma` file is the schema's blueprint.
#### Create `schema.prisma` File

```shell
npx prisma init
```
#### Code Example

```prisma
generator client {
  provider = "prisma-client"
  output   = "../src/generated/prisma"
}

datasource db {
  provider = "postgresql"
}

enum Stage {
  account_created
  pending_review
}

model User {
  id        String   @id @default(cuid())
  stage     Stage    @default(account_created)
  createdAt DateTime @default(now()) @map("created_at")
  updatedAt DateTime @updatedAt @map("updated_at")

  @@map("users")
}
```
#### Syntax Breakdown
| Syntax               | Meaning                                               |
| -------------------- | ----------------------------------------------------- |
| `generator client`   | Where/how to generate the TS client                   |
| `datasource db`      | Which DB engine (PostgreSQL, MySQL, etc.)             |
| `model User`         | Defines a table                                       |
| `enum Stage`         | Defines a fixed list of allowed values                |
| `@id`                | Primary key                                           |
| `@default(cuid())`   | Auto-generate ID on insert                            |
| `@default(now())`    | Auto-set timestamp on create                          |
| `@updatedAt`         | Auto-update on row change                             |
| `@map("created_at")` | DB column name (snake_case) vs field name (camelCase) |
| `@@map("users")`     | Actual table name in Postgres                         |


