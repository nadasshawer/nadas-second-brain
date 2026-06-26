## Express Middleware

A **middleware** function runs between the incoming request and the route handler.

```text
Request → middleware 1 → middleware 2 → controller → Response
```
#### Signature

```ts
(req, res, next) => { ... }
```

| Arg    | Role                                        |
| ------ | ------------------------------------------- |
| `req`  | Incoming request (headers, body, params)    |
| `res`  | Outgoing response                           |
| `next` | Pass control to the next middleware/handler |

- Call **`next()`** → continue the chain
- Send **`res.status(...).json(...)`** → stop; handler never runs
#### Common uses

- **Auth** → validate [JWT](jwt.md), attach `req.user`
- **Stage / role gates** → check permissions before the handler
- **Logging**, rate limiting, body parsing (`express.json()`)
#### Chaining on a route

```ts
router.get(
  "/path",
  authMiddleware,
  requireStage("profiling"),
  controller
);
```

- Runs left → right. First failure stops the chain.
