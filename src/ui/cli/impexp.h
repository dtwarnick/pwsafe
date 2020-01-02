/*
 * Created by Saurav Ghosh
 * Copyright (c) 2003-2020 Rony Shapiro <ronys@pwsafe.org>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

#pragma once

class PWScore;
struct UserArgs;

int Import(PWScore &core, const UserArgs &ua);
int Export(PWScore &core, const UserArgs &ua);

