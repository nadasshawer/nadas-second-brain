## Common Prisma CLI Commands

- **`npx`** → Node Package eXecute; runs a local package without global install
- **`prisma init`** → creates starter `prisma/schema.prisma` + config
#### Initialization
| Command                  | What it does                                               | What it generates                     |
| ------------------------ | ---------------------------------------------------------- | ------------------------------------- |
| `npx prisma init`        | Creates Prisma [[schema-file\|schema file]] in the project | `schema.prisma`<br>`prisma.config.ts` |
| `npx prisma generate`    | Build TypeScript client from schema                        | [generated/prisma](generated-dir%5C)  |
| `npx prisma migrate dev` | Create + apply a [migration](migrations%5C) (local dev)    | `prisma/migrations`                   |
| `npx prisma db push`     | Push schema to DB without a migration file                 |                                       |
| `npx prisma studio`      | Visual DB browser in the browser                           |                                       |
|                          |                                                            |                                       |
