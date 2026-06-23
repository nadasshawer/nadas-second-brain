## Express + TypeScript API

Reference layout for a Node.js REST API (Express, Prisma, Jest). Pair with [[local-setup|local PostgreSQL setup]] when wiring `DATABASE_URL`.
#### Root Files

- **`package.json`** → project metadata, npm scripts, dependencies
- **`package-lock.json`** → locked dependency versions (commit this)
- **`tsconfig.json`** → TypeScript compiler options (`strict`, output to `dist/`)
- **`jest.config.js`** → Jest test runner config (ts-jest preset)
- **`.env`** → local secrets — DB URL, API keys (never commit)
- **`.env.example`** → template for required env vars (commit this)
- **`.gitignore`** → files Git should ignore (`node_modules`, `.env`, `dist/`)
#### npm Scripts (typical)

- **`dev`** → `tsx watch src/app.ts` — local development with auto-reload
- **`build`** → `tsc` — compile TypeScript to `dist/`
- **`start`** → `node dist/app.js` — run production build
- **`test`** → `jest` — run automated tests
#### Folders

- **`src/`** → application source — Express app, routes, middleware, services
- **`tests/`** → Jest/Supertest specs (`*.test.ts`)
- **`prisma/`** → schema (`schema.prisma`) and database migrations
- **`scripts/curl/`** → shell scripts to hit API endpoints from the terminal
- **`node_modules/`** → installed packages (auto-generated; never commit)
- **`dist/`** → compiled JavaScript from `tsc` (gitignored)
#### `src/` (grows over time)

- `app.ts` → creates Express app, mounts middleware and routes
- Later → `routes/`, `middleware/`, `services/`, `types/`
#### `tests/` convention

- Mirror `src/` structure where helpful
- Name files `*.test.ts` (Jest picks them up via `jest.config.js`)
#### `prisma/` convention

- `schema.prisma` → models, enums, database connection
- `migrations/` → auto-generated SQL migration history
#### Environment Variables

```text
DATABASE_URL=postgresql://USER:PASSWORD@localhost:5432/DATABASE
PORT=3000
```

- Loaded at runtime via `import "dotenv/config"` in the entry file
- `DATABASE_URL` is read by Prisma; `PORT` by Express
