#include "init.h"

Init::Init() : filename(""), nx(0), ny(0), error_code(0) {}
Init::Init(Init const && other) : filename(other.filename), nx(other.nx), ny(other.ny) {}
Init::~Init() {}
