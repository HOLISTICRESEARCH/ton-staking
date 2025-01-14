/*
    This file is part of TON Blockchain Library.

    TON Blockchain Library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    TON Blockchain Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with TON Blockchain Library.  If not, see <http://www.gnu.org/licenses/>.

    Copyright 2017-2019 Telegram Systems LLP
*/
#pragma once

#include "StakingSmartContract.h"
#include "vm/cells.h"
#include "Ed25519.h"
#include "block/block.h"
#include "vm/cells/CellString.h"

namespace ton {
    class Nominator : public ton::StakingSmartContract {
    public:
        explicit Nominator(State state) :  ton::StakingSmartContract(std::move(state)) {
        }
        static constexpr unsigned max_message_size = vm::CellString::max_bytes;
        static td::Ref<vm::Cell> get_init_state(const block::StdAddress  owner_address, td::int32 wallet_id) noexcept;
        static td::Ref<vm::Cell> get_init_message() noexcept;

        static td::Ref<vm::Cell> get_init_code() noexcept;
        static vm::CellHash get_init_code_hash() noexcept;
        static td::Ref<vm::Cell> get_init_data(const block::StdAddress owner_address, td::uint32 wallet_id ) noexcept;

        td::Result<td::uint32> get_wallet_id() const;



        static td::Ref<Nominator> create(td::Ref<vm::Cell> data = {});



          private:
        td::Result<td::uint32> get_seqno_or_throw() const;
        td::Result<td::uint32> get_wallet_id_or_throw() const;

        vm::Ref<vm::Cell> dict_;

    };
}  // namespace ton
