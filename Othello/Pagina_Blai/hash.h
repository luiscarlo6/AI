#include "othello_cut.h"
#include <tr1/unordered_map>

struct stored_info_t
{
	// [information to be stored in hash table]
	stored_info_t() { } // need at least one ctor without arguments
};

struct hash_function_t : public tr1::hash<state_t>
{
	size_t operator()(const state_t &state) const
	{
		return state.hash();
	}
};

class hash_table_t : public tr1::unordered_map<state_t, stored_info_t, hash_function_t>
{
};