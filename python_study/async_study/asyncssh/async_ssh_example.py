#!/bin/env python3.6
import asyncio, asyncssh, sys

async def run_client():
    async with asyncssh.connect('ras') as conn:
        result = await conn.run('echo "Hello!"', check=True)
        print(result.stdout, end='')

try:
    asyncio.get_event_loop().run_until_complete(run_client())
except (OSError, asyncssh.Error) as exc:
    sys.exit('SSH connection failed: ' + str(exc))