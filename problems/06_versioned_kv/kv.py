class VersionedKV:
    def __init__(self):
        self._latest = {}

    def set(self, key: str, value: str, timestamp: int | None = None) -> None:
        # Existing API ignored timestamp; preserve latest get while you introduce history.
        self._latest[key] = value

    def get(self, key: str):
        return self._latest.get(key)

    def delete(self, key: str, timestamp: int | None = None) -> None:
        self._latest.pop(key, None)

    def get_at(self, key: str, timestamp: int):
        raise NotImplementedError
