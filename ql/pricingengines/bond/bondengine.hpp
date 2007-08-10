/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2007 Giorgio Facchinetti

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file bondengine.hpp
    \brief bond engine
*/

#ifndef quantlib_bond_engine_hpp
#define quantlib_bond_engine_hpp

#include <ql/instruments/bond.hpp>
#include <ql/termstructures/swaptionvolstructure.hpp>

namespace QuantLib {


    class BondEngine : public Bond::engine,
                       public Observer {
      public:
        BondEngine(const Handle<YieldTermStructure>& discountCurve = 
                                        Handle<YieldTermStructure>());
        void calculate() const;
        void update();
        Handle<YieldTermStructure> discountCurve() const;
      private:
        Handle<YieldTermStructure> discountCurve_;
    };

}


#endif